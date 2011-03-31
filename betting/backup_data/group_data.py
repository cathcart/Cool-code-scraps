import sys
import os
inputfile_uncorrected=sys.argv[1]

os.system("sh formate.sh %s>tmp"%inputfile_uncorrected)

inputfile=open("tmp")#data we need #no matches, GF, GA

#read in data
data=[]
for line in inputfile:
	items=line.split()
	data.append(items)

avg_goals=0
for point in data:
	tmp=float(point[2])/float(point[1])
	avg_goals+=float(point[2])/float(point[1])

avg_goals/=float(len(data))

for point in data:
	print point[0]," ",(float(point[2])/float(point[1]))/avg_goals," ",(float(point[3])/float(point[1]))/avg_goals
