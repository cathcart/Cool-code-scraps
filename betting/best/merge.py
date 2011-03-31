new_data=open("data_old")
old_data=open("06_weights")

new=[]
old=[]

for line in new_data:
	items=line.split()
	new.append([items[0],[float(items[1]),float(items[2])]])

for line in old_data:
	items=line.split()
	old.append([items[0],[float(items[1]),float(items[2])]])

NEW=dict(new)
OLD=dict(old)

#weights
a=0.6
b=1-a

def line(name,one,two):
	print name," ",a*one[0]+b*two[0]," ",a*one[1]+b*two[1]

for i in NEW:
	try:
		line(i,OLD[i],NEW[i])
	except:
		w=1
		line(i,[w*NEW[i][0],w*NEW[i][1]],[w*NEW[i][0],w*NEW[i][1]])

