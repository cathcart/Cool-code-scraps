proper=[]
def read_data():
	data=[]
	for line in open("thirteen.dat"):
		data.append(float(line))
		proper.append(int(line[:12]))
	return data

data=read_data()
sum=0
sum2=0
for i in proper:
	sum2+=i
print sum2
for i in data:
	sum+=i
print sum
