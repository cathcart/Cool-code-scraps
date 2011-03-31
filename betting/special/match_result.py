import poss
import string
import sys
#print sys.argv[1]
#fixtures=open("fixtures.data")
#fixtures=open(sys.argv[1])
def get_weights():
	weights_data=open("data")
	weights=[]
	weight=[0,0,0]
	#store the weights in memory
	for i in weights_data:
		items=i.split()
		weight=[string.lower(items[0]),[float(items[-2]),float(items[-1])]]
		weights.append(weight)
	weights_dictionary=dict(weights)
	return weights_dictionary

#weights_0=[9,9]
#weights_1=[9,9]
#for match in fixtures:
#	teams=match.split()
	#get weights for these teams
def match_result(teams):
		weights=get_weights()
		weights_0=weights[teams[0]]
		weights_1=weights[teams[1]]
		#call result from poss and get the result
		#print "%s V %s: " %(teams[0],teams[1]),
		return poss.result(weights_0[0]*weights_1[1],weights_1[0]*weights_0[1])

	
