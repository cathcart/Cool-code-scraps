import string
in_file=open("final2")

records=[]
for i in in_file:
	items=i.split()
	records.append(items)

i=0
while i <=len(records):
	if string.lower(records[i+1][0])==string.lower(records[i][0]):
		print string.lower(records[i][0])," ",(float(records[i][1])+float(records[i+1][1]))/2.0,(float(records[i][2])+float(records[i+1][2]))/2.0 
		i+=1
	else:
		print string.lower(records[i][0])," ",records[i][1]," ",records[i][2]
	i+=1


