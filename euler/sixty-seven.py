import time

def read_data():
	data=[]
	in_put=open("sixty-seven.dat")
	for line in in_put:
		items=line.split()
		tmp=[]
		for i in items:
			tmp.append(int(i))
		data.append(tmp)
	return data

def simple(data):
	results=[[data[0][0]]]
	for row in range(1,len(data)):
		row_results=[]
		for col in range(len(data[row])):
			if col==0:
				row_results.append(data[row][col]+results[row-1][col])
			elif col==len(data[row])-1:
				row_results.append(data[row][col]+results[row-1][-1])
			else:
				row_results.append(max([data[row][col]+results[row-1][col],data[row][col]+results[row-1][col-1]]))
		results.append(row_results)
	return max(results[-1])


if __name__=="__main__":
	tStart=time.time()
	data=read_data()
	print simple(data)
	print "Run Time = " + str(time.time() - tStart)
