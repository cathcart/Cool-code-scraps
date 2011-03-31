import time
#import random

def read_data():
	data=[]
	in_put=open("eighteen-2.dat")
	for line in in_put:
		items=line.split()
		tmp=[]
		for i in items:
			tmp.append(int(i))
		data.append(tmp)
	return data
'''
def inital_walk(data):
	k=0
	path=[0,]
	for i in range(1,len(data)):
		if random.random()<0.5:
			new=data[i][k]
		else:
			new=data[i][k+1]
                k=data[i].index(new)
		path.append(k)
	return path

def path_cost(path,data):
	sum=0
	t=0
	for i in path:
		sum+=data[t][i]
		t+=1
	return sum

def path_alter(path,k):
	new_path=[]
	for i in range(len(path)):
		if i<k:
			new_path.append(path[i])
		else:
			if path[k]-path[k-1]==0:
				new_path.append(path[i]+1)
			else:
				new_path.append(path[i]-1)		
	return new_path

def max_path(data):#wrong
	path=[0,]
	for i in range(1,len(data)):
		temp=max([data[i][path[-1]],data[i][path[-1]+1]])
		path.append(data[i].index(temp))
	return path
def SA():
        data=read_data()
        path=inital_walk(data)
        T_max=200000
        for T in range(0,T_max):
                #generate a new 'test' path
                try:
                        new_path=path_alter(path,int(len(path)*random.random()))
                        if path_cost(new_path,data)>path_cost(path,data):
                                path=new_path[:]
                        else:
                                if (T)/T_max >random.random():
                                        path=new_path[:]
                except:
                        pass
        print path_cost(path,data)
'''

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
