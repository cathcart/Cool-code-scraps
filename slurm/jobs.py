import time
def read_data(in_file):
  '''reads the input file in and arrages the data as we wish'''
  
  text=open(in_file).read()
  jobs=text.strip().split("\n\n")
  return jobs

class JOB:
  def __init__(self,data):
    self.dic={}
    for i in data.split():
      [item,value]=i.split("=")
      self.dic[item]=value

  def __getitem__(self,item):
    return self.dic[item]

  def keys(self):
    return self.dic.keys()

  def items(self):
    return self.dic.items()

def parse_jobs(jobs):
  job_list=[]
  for a_job in jobs:
   job_list.append(JOB(a_job))
  return job_list

class JOB_LIST:
  def __init__(self,data):
    self.data=data

  def __add__(self,other):
    self.data=self.data+[other]

  def subset(self,key,value):
    sub=[]
    for job in self.data:
      if(job[key]==value):
        sub.append(job)
    return sub

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
    report_string="SLURM Report\n"
    report_string+=time.ctime(time.time())+"\n\n"

    stats=self.status()
    for key in stats:
      report_string+="%s: %d" %(key,stats[key])+"\n"
    for key in stats:
      for job in self.subset("JobState",key):
        report_string+="%s %s %s %s"%(job["JobId"],job["Name"],job["WorkDir"],job["Partition"]) +"\n"
    return report_string
  
if __name__=="__main__":

  slurm_job_list=parse_jobs(read_data("tmp"))
  my_job_list=JOB_LIST([])
  for a_job in slurm_job_list:
    user=a_job["UserId"]
    if user.split("(")[0]=="cathcart":
      my_job_list+a_job

  print my_job_list.compile_report()
  
