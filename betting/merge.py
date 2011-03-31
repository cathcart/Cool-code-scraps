new_data=open("10_unique")
old_data=open("06_weights")

new=[]
old=[]

#weights
a=0.25
b=0.75

def present(n,list):
	k=-9
	for i in range(len(list)):
		if list[i][0]==n:
			k=i
	if k>=0:
		return k
	else:
		return False

for i in new_data:
	items=i.split()
	new.append(items)
for i in old_data:
	items=i.split()
	old.append(items)
for i in new:
	t=present(i[0],old)
	if t!=False:
		print old[t][0]," ",a*float(old[t][1])+b*float(i[1])," ",a*float(old[t][2])+b*float(i[2])
	else:
		print i[0]," ",i[1]," ",i[2]
