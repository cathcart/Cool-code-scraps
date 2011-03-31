import os
import math
from threading import Thread

class Vector:
  def __init__(self, data):
    self.data = data
  def __repr__(self):
    return repr(self.data)  
  def __add__(self, other):
    return Vector([self.data[j]+other.data[j] for j in range(len(self.data))])
  def __getitem__(self,index):
    return self.data[index]
  def __mul__(self,factor):
    return Vector([factor*x for x in self.data])
  def __rmul__(self,factor):
    return self*factor

def gen_unit_cell(lattice_vectors):

    ##these are the experimental parameters from the navy website, they appear to give correct results
    fractional_coords=[[-0.15000000,0.15000000,0.11700000],[0.15000000,-0.15000000,-0.11700000],[0.35,0.65,0.383],[0.65,0.35,0.617]]
    #lattice_vectors=[[3.62500000,-2.39500000,0.00000000],[3.62500000,2.39500000,0.00000000],[0.0,0.0,9.78]]

    atoms=[]
    for j in range(len(fractional_coords)):
      a=Vector([0,0,0])
      for i in range(3):
        v=Vector(lattice_vectors[i])
        a+=v*fractional_coords[j][i]
        #a+=Vector([(fractional_coords[j][i])*x for x in v])
      atoms.append(a)
      #atoms.append(a.tolist())

    return atoms

    #return expand(atoms,lattice_vectors)#expand up to the supercell

def distance(atom1,atom2):
    return math.sqrt(sum([(atom2[i]-atom1[i])**2 for i in range(3)]))

def pair_wise_force(atom1,atom2):
    d=distance(atom1,atom2)
    if d!= 0:
      #return 1.0/distance(atom1,atom2)
      return (1.0/distance(atom1,atom2)**13)+(1.0/distance(atom1,atom2)**7)
    else:
      return 0.0

def compile_distances(atoms):
    l=[]#l for list 

    for atom1 in atoms:
      for atom2 in atoms:
        if atom2 != atom1:
          d=distance(atom1,atom2)#d for distance
          if d not in l:
            l.append(d)

    return sorted(l)

def expand(atoms,lattice_vectors):
    l=[]#l for list

    #core=[Vector(x) for x in atoms]
    core=atoms

    n=1#this is the number of unit cell layers in the supercell, so n=1 -->12 (??)    
    t=[[x,y,z] for x in range(n) for y in range(n) for z in range(n)]

    for N in t:
      #for atom_non_vector in atoms:
      for atom in atoms:
        #atom=Vector(atom_non_vector)
        for i in range(3):
          new_atom=atom+N[i]*lattice_vectors[i]
          #new_atom=atom+Vector([N[i]*x for x in lattice_vectors[i]])
          if new_atom not in l:
            l.append(new_atom)

    return l

def two_step_sum():
    unit_cell=gen_unit_cell(lattice_vectors)
    all_atoms=expand(unit_cell,lattice_vectors)
    outside_unit_cell=[x for x in all_atoms if x not in unit_cell]

    internal_force=0#force from within the unit cell
    for i in range(len(unit_cell)):
      atom1=unit_cell[i]
      for j in range(i,len(unit_cell)):
        atom2=unit_cell[j]
        internal_force+=pair_wise_force(atom1,atom2)

    external_force=0#force of atom inside the unit cell with those outside
    for atom1 in unit_cell:
      for atom2 in outside_unit_cell:
        external_force+=pair_wise_force(atom1,atom2)

    return internal_force+external_force#this is the total force

def two_step_sum_thread():
    unit_cell=gen_unit_cell(lattice_vectors)
    all_atoms=expand(unit_cell,lattice_vectors)
    outside_unit_cell=[x for x in all_atoms if x not in unit_cell]

    internal_force=0#force from within the unit cell
    for i in range(len(unit_cell)):
      atom1=unit_cell[i]
      for j in range(i,len(unit_cell)):
        atom2=unit_cell[j]
        internal_force+=pair_wise_force(atom1,atom2)

    external_force=0#force of atom inside the unit cell with those outside
    for atom1 in unit_cell:
      def one(atom1):
        force_total=0
        for atom2 in outside_unit_cell:
          force_total+=pair_wise_force(atom1,atom2)
        return force_total
      
      t=Thread(target=one,args=(atom1,))
      t.start()

    return internal_force+external_force#this is the total force


def gen_params(a):
    #create the b and c lists first then loop through then creating the combinded result
    b_list=[]
    c_list=[]
    list=[]
    b_0=a[1]
    c_0=a[2]
    p=0.3
    N=10
    n=N-1
    c_step=(2*p*c_0)/n
    b_step=(2*p*b_0)/n
    b=b_0*(1-p)
    c=c_0*(1-p)
    while (b<(b_0*(1+p))):
        b_list.append(b)
        b+=b_step
    while (c<(c_0*(1+p))):
        c_list.append(c)
        c+=c_step
    for b in b_list:
        for c in c_list:
            point=[a[0],b,c]
            list.append(point)
    return list

if __name__=="__main__":
    a=[7.25,4.275,9.78]
   
    for x in gen_params(a):
      lattice_vectors=[[x[0]/2,-x[1]/2,0.00000000],[x[0]/2,x[1]/2,0.00000000],[0.0,0.0,x[2]]]
      lattice_vectors=[Vector(x) for x in lattice_vectors]
      print "%f %f %f %f" %(x[0],x[1],x[2],two_step_sum_thread())
