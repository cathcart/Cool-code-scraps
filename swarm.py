import random
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

class Particle:

  def __init__(self,data):
    self.position=Vector(data[0])
    self.velocity=Vector(data[1])
    self.local_extrema=Vector(data[0])

  #def __repr__(self):
  #  return repr([self.position,self.velocity])
  
  def update_position(self,new_position):
    self.position=self.position+Vector(new_position) 

  def update_velocity(self,new_velocity):
    self.velocity=self.velocity+Vector(new_velocity)

  def update_local_extrema(self):
    if self.position < self.local_extrema:
      self.local_extrema=self.position

  def update(self,data):
    self.update_velocity(data)
    self.update_position()    
    self.update_local_extrema()

  def position(self):
    print "dear god you're calling the position function/method"
    return self.position

  def cost(self,value):
    self.cost=value

  def print_cost(self):
    return self.cost

def r():
  yield random.random()

def function(parameters):
  [x1,x2]=parameters
  return 100*(x2-x1**2)**2+(1-x1)**2


if __name__=="__main__":
  N=5#number of particles
  swarm=[]#list of swarm particles
  p=2#number of parameters
  min_p=Vector([0,0])#min parameters
  max_p=Vector([1,1])#max_parameters
  K_l=1#local vector constant divided by the particle mass
  K_g=1#global vector constant divided by the particle mass
  #initialise position and velocity for each particle

  for particle in range(N):
    position=[(min_p+(max_p-min_p)*next(r()))[i] for i in range(p)]
    velocity=[((max_p-min_p)*(2*next(r())-1))[i] for i in range(p)]
    swarm.append(Particle([position,velocity]))

  #distribute and calculate the value of the function at all of these points
  for iteration in range(10):
    for particle in swarm:
      particle.cost(function(particle.position))
    #update all the local extrema and decide the new global extrema
    particles_cost=[particle.print_cost() for particle in swarm]
    min_index=particles_cost.index(min(particles_cost))
    print "here we are"
    t=swarm[min_index]
    print type(swarm)
    print swarm[0]
    print min_index
    print type(min_index)
    print 
    print (swarm[min_index]).cost()


    quit()
    print type(t)
    print t.position()
    print (swarm[min_index]).position()
    min_position=Vector(swarm[min_index].position())
    #update paticle velocities, positions and local_extrema
    for particle in swarm:
      local_vector=particle.local_extrema()-particle.position()
      global_vector=min_position-particle.position()
      [r_l,r_g]=[next(r()) for i in range(2)]
      update_vector=r_l*local_vector+r_g*global_vector
      particle.update(update_vector)
      
