import poss
import string
import sys
#print sys.argv[1]
#fixtures=open("fixtures.data")
fixtures=open(sys.argv[1])
weights_data=open("final_data")

weights=[]
weight=[0,0,0]
#store the weights in memory
for i in weights_data:
	items=i.split()
	weight=[string.lower(items[0]),float(items[-2]),float(items[-1])]
	weights.append(weight)

weights_0=[9,9]
weights_1=[9,9]
for match in fixtures:
	teams=match.split()
	#get weights for these teams
	for item in weights:
		if item[0]==string.lower(teams[0]):
			weights_0=[item[1],item[2]]
		if item[0]==string.lower(teams[1]):
			weights_1=[item[1],item[2]]
	if weights_0[0]==9:
		print "%s weights not found"%teams[0]
	if weights_1[0]==9:
		print "%s weights not found"%teams[1]
	#call result from poss and get the result
	print "%s V %s: " %(teams[0],teams[1]),
	print poss.result(weights_0[0]*weights_1[1],weights_1[0]*weights_0[1])

	
