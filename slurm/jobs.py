import time
def read_data(in_file):
  '''reads the input file in and arrages the data as we wish'''
  
  text=open(in_file).read()
  jobs=text.strip().split("\n\n")
  return jobs

class JOB:
  '''define a JOB class. this is a dict of key value pairs'''
  def __init__(self,data):
    self.dic={}
    for i in data.split():
      try:
        [item,value]=i.split("=",1)
      except:
        print i
      self.dic[item]=value.split("(")[0]

  def __getitem__(self,item):
    return self.dic[item]

  def keys(self):
    return self.dic.keys()

  def items(self):
    return self.dic.items()

def parse_jobs(jobs):
  '''This parses the raw input text into list of JOB objects'''
  job_list=[]
  for a_job in jobs:
   job_list.append(JOB(a_job))
  return job_list

class JOB_LIST:
  '''This defines a list of JOB objects and methods to pull data from the individial JOBS''' 
  def __init__(self,data):
    self.data=data

  def __getitem__(self,item):
    '''Get a single JOB object'''
    return self.data[item]
  
  def __add__(self,other):
    self.data=self.data+[other]

  def subset(self,key,value):
    '''Use this to pull all the objects from the list whos value for a given key matches the given value'''
    sub=[]
    for job in self.data:
      if(job[key]==value):
        sub.append(job)
    return JOB_LIST(sub)

  def status(self):
    job_states={}
    for job in self.data:
      state=job["JobState"]
      if state in job_states:
        job_states[state]+=1
      else:
        job_states[state]=1
    return job_states

  def compile_report(self):
    report_string="SLURM Report\\n"
    report_string+=time.ctime(time.time())+"\\n\\n"

    stats=self.status()
    for key in stats:
      report_string+="%s: %d" %(key,stats[key])+"\\n"
    for key in stats:
      report_string+=key+"\\n"
      for job in self.subset("JobState",key):
        report_string+="%s %s %s %s"%(job["JobId"],job["Name"],job["WorkDir"],job["Partition"]) +"\\n"
    return report_string
  
if __name__=="__main__":
  user_name="YOUR SLURM USER NAME"

  slurm_job_list=JOB_LIST(parse_jobs(read_data("tmp")))
  my_job_list=slurm_job_list.subset("UserId",user_name)
  print my_job_list.compile_report()
  my_job_list=JOB_LIST([])
