''' code to parse siesta pseudopotentials to plot out the different variables'''
from optparse import OptionParser
class pseudo:
  def __init__(self,file):
    self.file=file
    self.lines=[x.strip() for x in open(self.file)]

  def get_parameters(self):
    #lines=[x for x in open(self.file)]
    [self.num_v,b,self.np,self.first,self.b,self.valence]=self.lines[3].strip().split()

  def get_mesh(self):
    self.get_parameters()
    s=self.lines.index("Radial grid follows")
    for l in self.lines[s+1:s+2+int(self.np)/4]:
      for x in l.split():
        yield x

  def get_potential(self,number):
    self.get_parameters()
    '''search near to where we expect the lth potential data to be, that is the (number of mesh points/4 +1)*l'''
    s=self.lines.index("Down Pseudopotential follows (l on next line)",(number+1)*(int(self.np)/4))
    for l in self.lines[s+2:s+3+int(self.np)/4]:
      for x in l.split():
        yield x

  def get_valence(self):
    self.get_parameters()
    s=self.lines.index("Valence charge follows")
    for l in self.lines[s+1:s+2+int(self.np)/4]:
      for x in l.split():
        yield x

  def parse(self,number):
    for x in zip(self.get_mesh(), self.get_potential(number)):
      print float(x[0]),float(x[1])

  def parse2(self):
    for x in zip(self.get_mesh(), self.get_valence()):
      print float(x[0]),float(x[1])

if __name__=="__main__":
  usage="Usage: %prog Input_psf variable_to_parse"
  parser=OptionParser(usage=usage)
  #parser.add_option("-f","--file",dest="filename",help="input FILE",metavar="FILE")
  (options,args)=parser.parse_args()
  if len(args) != 2:
    print "Errror\n",usage
  try:
    f=pseudo(args[0])
  except e:
    print "Problem opening ", args[0]  
  if args[1].lower()=="valence":
    print "Parsing the valence charge"
    f.parse2()
  else:
    print "Parsing the potential", int(args[1])
    f.parse(int(args[1]))
  
 

  #a=pseudo("Ar.psf")
  #b=pseudo("siesta_Ar.psf")
  #a.parse2()

