import math
import random
import multiprocessing
class Vector:
  def __class__(self):
    return "Vector"
  def __init__(self, data):
    self.data = data
  def __repr__(self):
    return repr(self.data)  
  def __add__(self, other):
    data = []
    for j in range(len(self.data)):
      data.append(self.data[j] + other.data[j])
    return Vector(data)
  def __sub__(self,other):
    return self+(-1)*other
  def __len__(self):
    return len(self.data)
  def __rmul__(self,time):
    return self*time
  def __mul__(self,time):
    return Vector([time*self.data[i] for i in range(len(self.data))])
  def __getitem__(self,index):
    return self.data[index]
  def __setitem__(self,index,value):
    self.data[index]=value

class Particle:
  def __init__(self,data):
    self.position=Vector(data[0])
    self.velocity=Vector(data[1])
    self.local_min=Vector(data[0])
    self.mass=0.8
  def update_position(self):
    self.position=self.position+self.velocity
  def update_velocity(self,new_velocity):
    self.velocity=self.mass*self.velocity+Vector(new_velocity)
  def update_local_min(self):
    if self.position < self.local_min:
      self.local_min=self.position
  def update(self,data):
    self.update_velocity(data)
    self.update_position()    
    self.update_local_min()
  def set_cost(self,value):
    self.cost=value

def distance(one,two):
  return math.sqrt(sum([(one[i]-two[i])**2 for i in range(len(one))]))

def bound(x,l,u):

  if x < l :
    return l
  if x > u :
    return u

  return x

def grouping(vector_list,n):
  l=[]
  tmp_list=vector_list
  groups=[]
  t=len(vector_list)/n
  for one in vector_list[0::len(vector_list)/n]:
    sorted_list=sorted(tmp_list,key=lambda x: distance(one.position,x.position))
    groups.append(sorted_list[0:len(vector_list)/n])
    tmp_list=tmp_list[len(vector_list)/n::]
  return groups

def r():
  yield random.random()

def my_function(parameters):
  [x1,x2]=parameters
  return 100*(x2-x1**2)**2+(1-x1)**2

def run(N,iterations,grouping_N,min_p,max_p,function):
  #N=20#number of particles
  #grouping_N=6#number of groups to slip the swarm into for the local group mins
  #iterations=100#number of iterations to run
  #min_p=Vector([0,0])#min parameters
  #max_p=Vector([20,20])#max_parameters
  K_l=0.0#local vector constant 
  K_g=2.8446#global vector constant 
  K_gv=0.0#group vector constant
  mass=-0.3328
  #[K_l,K_g,k_gv]=constants
  p=len(min_p)#number of parameters
  swarm=[]#list of swarm particles

  #initialise position and velocity for each particle
  for particle in range(N):
    position=[(min_p+(max_p-min_p)*next(r()))[i] for i in range(p)]
    velocity=[((max_p-min_p)*(2*next(r())-1))[i] for i in range(p)]
    swarm.append(Particle([position,velocity]))

  #distribute and calculate the value of the function at all of these points
  min_position=min_p

  for iteration in range(iterations):

#    print "%d %f" %(iteration,min_position[0])
    p=multiprocessing.Pool(6)
    cost_results=p.map(function,[particle.position for particle in swarm])
    [swarm[i].set_cost(cost_results[i]) for i in range(len(swarm))]

    #update all the local extrema and decide the new global extrema
    min_position=sorted(swarm,key=lambda x: x.cost)[0].position
    groups=grouping(swarm,grouping_N)
    for group in groups:
      group_position=sorted(group,key=lambda x: x.cost)[0].position
      for particle in group:

        global_vector=min_position-particle.position
        local_vector=particle.local_min-particle.position
        group_vector=group_position-particle.position

        [r_l,r_g,r_gv]=[next(r()) for i in range(3)]

        update_vector=(K_l*r_l*local_vector+K_g*r_g*global_vector+K_gv*r_gv*group_vector)
        velocity=mass*particle.velocity+update_vector
        velocity=[bound(velocity[i],-1*(max_p-min_p)[i],(max_p-min_p)[i]) for i in range(len(velocity))]
        particle.velocity=Vector(velocity)
        position=particle.position+particle.velocity
        position=[bound(position[i],min_p[i],max_p[i]) for i in range(len(position))] 
        particle.position=Vector(position)
        #particle.update(update_vector)

        #check min
        mi=particle.position-min_p
        for i in [y for y in mi if y <= 0]:
          x=mi.data.index(i)
          particle.position[x]=min_p[x]
          particle.velocity[x]=0

        #check max
        ma=particle.position-max_p
        for i in [y for y in ma if y >= 0]:
          x=ma.data.index(i)
          particle.position[x]=max_p[x]
          particle.velocity[x]=0

  p=sorted(swarm,key=lambda x: x.cost)[0].position
  return [math.sqrt(sum([i**2 for i in p])),p]

def test(parameters):
  [N,iterations]=[int(x) for x in parameters]
  min_p=Vector([0,0])
  max_p=Vector([2,2])
  return run(N,iterations,1,min_p,max_p,my_function)[0]

if __name__=="__main__":
  #best=[int(x) for x in run(100,10000,1,Vector([5,10]),Vector([100,100]),test)[1]]
  #print best
  min_p=Vector([0,0])
  max_p=Vector([20,20])
  #print run(best[0],best[1],1,min_p,max_p,my_function)
  print run(50,400,1,min_p,max_p,my_function)
