#!/usr/bin/python

from collections import defaultdict
import subprocess
import math

def parse_simulation_output(simulation_output, gravity_values):
    """read in the simulation output, return a dict of all values"""
    fudge_factor = 1.0    # to fix the sim output - see Hutzler
    temp_list = []
    number_of_profiles = 7
    try:
        sim_data = open('DATA/profiles.dat', 'r')
    except Exception, e:
        raise e
    
    current_grav_value = 0

    for line in sim_data:
        split_line = line.split()
        if split_line:
            if split_line[1] == 'GRAVITY_CHANGE':
                current_grav_value = split_line[-1]
                if len(gravity_values) < number_of_profiles:
                    gravity_values.append(str(current_grav_value))
            else:
                # 1985 includes 450 offset to match sim with expt
                position = str(500 + int(math.ceil(float(split_line[0]))))
                liquid_fraction = fudge_factor * float(split_line[4])
                simulation_output[current_grav_value][position] = liquid_fraction

    sim_data.close()

def parse_experimental_data(experiment_output, gravity_values):
    """load the experimental data into the same format as the sim output"""
    try:
        exp_data = open('DATA/experiment.dat', 'r')
    except Exception, e:
        raise e  

    for line in exp_data:
        split_line = line.split()
        if split_line:
            experiment_output[gravity_values[0]][split_line[0]] = float(split_line[6] )/100.0
            experiment_output[gravity_values[1]][split_line[0]] = float(split_line[7] )/100.0
            experiment_output[gravity_values[2]][split_line[0]] = float(split_line[8] )/100.0
            experiment_output[gravity_values[3]][split_line[0]] = float(split_line[9] )/100.0
            experiment_output[gravity_values[4]][split_line[0]] = float(split_line[11])/100.0
            experiment_output[gravity_values[5]][split_line[0]] = float(split_line[12])/100.0
            experiment_output[gravity_values[6]][split_line[0]] = float(split_line[13])/100.0

    exp_data.close()
            


def calculate_fit(simulation_data, experimental_data, gravity_values):
    r_squared = 0
    #for grav in gravity_values:
    grav = gravity_values[2]
    for pos in [i for i in simulation_data[grav] if experimental_data[grav].has_key(i) and int(i) < 1200]:
        if simulation_data[grav][pos] < 0.36:
            r_squared = r_squared + (float(simulation_data[grav][pos]) - float(experimental_data[grav][pos])) ** 2

    return float(r_squared) / len(gravity_values)

def run_drainage_sim(variables, initial_liquid_fraction):
    """docstring for run_drainage_sim"""
    sim_command = "./my_mu_g"
    for var in variables:
        sim_command = sim_command + " " + str(var)

    sim_command = sim_command + " " + str(initial_liquid_fraction)

    subprocess.check_call(sim_command, shell=True)

def complete_fitting_run(variables, initial_liquid_fraction, simulation_data, experimental_data, gravity_values):
    """run a sim and fitting run, returning a fit"""
    run_drainage_sim(variables, initial_liquid_fraction)

    parse_simulation_output(simulation_data, gravity_values)
    parse_experimental_data(experimental_data, gravity_values) 
    return calculate_fit(simulation_data, experimental_data, gravity_values)



if __name__ == '__main__':

    tolerance = 0.05

    gravity_values = []

    current_gamma = 0.700
    current_eta = 0.0011
    current_rho = 2300.0
    initial_variables = [current_gamma, current_eta, current_rho]        
    variables = [current_gamma, current_eta, current_rho]

    initial_liquid_fraction = 0.20

    
    gamma_step = 0.25
    eta_step = 0.00045
    rho_step = 200.0

    steps = [gamma_step, eta_step, rho_step]
    simulation_data = defaultdict(dict) 
    experimental_data = defaultdict(dict)

    run_drainage_sim(variables, initial_liquid_fraction)

    parse_simulation_output(simulation_data, gravity_values)
    parse_experimental_data(experimental_data, gravity_values)            

    # enter while loop first time
    new_fit = 2.0
    old_fit = 1.0

    while abs((new_fit-old_fit)/new_fit) > tolerance:
        print("Variables: gamma = %2.5f\t eta = %2.5f\t rho = %5.2f" % (variables[0], variables[1], variables[2]))
        print("current fit ratio = %5.5f" % (abs((new_fit - old_fit)/new_fit)))
        print gravity_values[0:10]

        old_fit = calculate_fit(simulation_data, experimental_data, gravity_values)

        for i in range(len(variables)):
            plus_variables = [0 for x in variables] 
            minus_variables = [0 for x in variables]
            
            for k in range(len(variables)):
                if k == i:
                    plus_variables[i] = variables[i] + steps[i]
                    minus_variables[i] = variables[i] - steps[i]
                else:
                    plus_variables[k] = variables[k]
                    minus_variables[k] = variables[k] 

            # calculate the fit for plus variables
            plus_fit = complete_fitting_run(plus_variables, initial_liquid_fraction, simulation_data, experimental_data, gravity_values)

            # calculate fit for minus variables
            minus_fit = complete_fitting_run(minus_variables, initial_liquid_fraction, simulation_data, experimental_data, gravity_values)

            # and for standard variables
            inner_fit = complete_fitting_run(variables, initial_liquid_fraction, simulation_data, experimental_data, gravity_values)

            # calculate new variables
            try:
                variables[i] = variables[i] - (0.5*steps[i])*((plus_fit - minus_fit) / (plus_fit - 2.0*inner_fit + minus_fit))
            except Exception,e:
                print variables
                raise e

            # decrease the stepsize
            steps[i] = 0.5*steps[i]

        new_fit = complete_fitting_run(variables, initial_liquid_fraction, simulation_data, experimental_data, gravity_values)
    print "Completed\n"
    print variables
    print new_fit                               

