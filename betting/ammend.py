




corrected_data=open("06_weights")

data=[]

for i in corrected_data:
	items=i.split()
	data.append(items)

list=[]
for i in data:
	list.append(i[0])


for i in open("10_unique"):
	items=i.split()
	if items[0] in list:
		for j in data:
			if items[0]==j[0]:
				print j[0]," ",j[1]," ",j[2]
	else:
		print i

	
