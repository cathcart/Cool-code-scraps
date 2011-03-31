import sys
import string
import re
input_file=sys.argv[1]

infile=open(input_file)

group=dict({})

for line in infile:
    items=line.split()
    if items[0] != "Group":
        name=items[0][2:]
        num_start=1
        if str.isalpha(items[1]):
            name=name+"-"+items[1]
            num_start+=1
        name=string.lower(name)
        temp_list=[]
        for i in [num_start,num_start+4,num_start+5,num_start+6]:#print no._matches,GF,GA,pts
            items[i]=float(items[i].rstrip('-'))
            temp_list.append(items[i])
        group[name]=temp_list

#sort the teams by the number of pts
e=group.keys()
e.sort(lambda a,b: -1*cmp(group[a][3],group[b][3]))#sort keys according to pts
#print e
#for i in range(len(e)-1):
    #print e[i]," ",group[e[i]][3]-group[e[i+1]][3]
difference=group[e[0]][3]-group[e[1]][3]#this is the pts diff between 1st and 2nd (take this as a measure of the group)
#print max([(group[x],x) for x in group])[0][3]#max pts value
for x in group:
    print x," ",difference," ",group[x][3]
