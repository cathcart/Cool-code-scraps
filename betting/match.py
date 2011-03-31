import poss
in_file=open("06_weights")


records=[]
record=[0,0,0]
for i in in_file:
	items=i.split()
	record=[items[0],float(items[1]),float(items[2])]
	records.append(record)

team1="ENGLAND"
team2="USA"

required1=[0,0]
for i in records:
	if i[0]==team1:
		required1=[i[1],i[2]]
	if i[0]==team2:
		required2=[i[1],i[2]]


print "In the match of %s against %s, we find the result to be: " %(team1,team2)
print poss.result(required1[0]*required2[1],required2[0]*required1[1])
