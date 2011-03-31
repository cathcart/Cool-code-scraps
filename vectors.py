class Vector: 
  def __init__(self, data):
    self.data = data
  def __repr__(self):
    return repr(self.data)  
  def __add__(self, other):
    data = []
    for j in range(len(self.data)):
      data.append(self.data[j] + other.data[j])
    return Vector(data)
  def __len__(self):
    return len(self.data)
  def __mul__(time,self):
    return Vector([time*self.data[i] for i in range(len(self.data))])
  def __mul__(self,time):
    return Vector([time*self.data[i] for i in range(len(self.data))])

def ans():
#  vectors=[[3.62500000,-2.39500000,0.00000000],[3.62500000,2.39500000,0.00000000],[0.00000000,0.00000000,9.78000000]]
#  
#  fractional_coords=[[0.14984988,-0.15086668,0.04001184],[0.22436604,-0.23748247,-0.10113813],[0.39914637,0.71167547,0.45835314],[0.05072043,0.81337519,0.48610750]]

  vectors=[[3.62500000,-2.39500000,0.00000000],[3.62500000,2.39500000,0.00000000],[0.00000000,0.00000000,9.78000000]]

  fractional_coords=[[-0.15000000,0.15000000,0.11700000],[0.15000000,-0.15000000,-0.11700000],[0.35000000,0.65000000,0.38300000],[0.65000000,0.35000000,0.61700000]]

  new_vec=[]
  for vec in vectors:
    new_vec.append(Vector(vec))

#  print "new vector test"
#  a=Vector([1.1,1.1,0])
#  print a
#  print a+a
#  print a*2
#  print type(a)
#
#  atom=fractional_coords[0]
#  vec=new_vec[0]
#  print type(new_vec[0])
#  print type(new_vec)
#  print vec*3
#  print new_vec[0]*3
#  print new_vec[0]*atom[0]

#  print Vector([2.0*vectors[0][i] for i in range(3)])+Vector([2.0*vectors[1][i] for i in range(3)])

  for atom in fractional_coords:
    print Vector([atom[0]*vectors[0][i] for i in range(3)])+Vector([atom[1]*vectors[1][i] for i in range(3)])+Vector([atom[2]*vectors[2][i] for i in range(3)])

  other=[
          [6.850259932,      -4.525895872,       0.000000000],               
          [6.850259932,       4.525895872,       0.000000000],       
          [0.000000000,       0.000000000,      18.481528865]]

  other2=[
  [-1.642755625,      -0.140589642,       6.396532927],
  [ 0.530922128,      -3.487297287,      -7.448501257],
  [11.184925515,      -5.929635632,       1.811486518],
   [3.208939821,      11.077137667,      15.667254802]]
  
#  print
#  for i in other:
#    for k in range(3):
#      print 0.529177249*i[k],
#    print
#  print
#  for i in other2:
#    for k in range(3):
#      print 0.529177249*i[k],
#    print

if __name__=="__main__":
  ans()
