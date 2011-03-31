'''
#global
paths=[]

def start(n):
	x,y=0,0
	path=[]
	for i in range(n+1):
		x=i
		path.append((x,y))
	for i in range(1,n+1):
		x=n
		y=i
		path.append((x,y))
	return path

def flip(path,t):
	\'''flip the t th point in the given path\'''
	tmp=path[:]
	tmp[t]=(tmp[t][0]-1,tmp[t][1]+1)
	return tmp
def legal(path,t):
	#apply flip and get new path
	test=flip(path,t)
	#check to see path is legal
	#check forward and back
	if test[t-1][0]==test[t][0] or test[t-1][1]==test[t][1]:
		if test[t+1][0]==test[t][0] or test[t+1][1]==test[t][1]:
			return 1
		else:
			return 0
	else:
		return 0

def flip_iteration(path,n):
        for i in range(1,2*n):#loop over all points but the first and last
                if legal(path,i):#check legality of flip
                        legal_path=flip(path,i)
                        if legal_path not in paths:
                                paths.append(legal_path)

def reverse(path):
	tmp=[]
	for i in path:
		tmp.append((i[1],i[0]))
	return tmp
'''
#def pascal(n):
#	r=n+1
#	list=[]
#        for c in range(n+1):
#                if c ==0:
#                        list.append(1)
#                        previous=1
#                else:
#                        list.append(previous*(r-c)/c)
#			previous*=(r-c)/c
#	return list

def pascal2(n):
	r=n+1
	list=[1,]
	for c in range(1,(n+1)/2+1):
		t=list[-1]
		list.append((r-c)*int(float(t/c)))
	return list[-1]

if __name__=="__main__":
	#3x3 cube is on the 6th line therefor the nxn cube will be on the 2*nth line
	N=20
	print pascal2(2*N)
	#for n in range(0,2*N+1,2):
#		ans=pascal2(n)
#	print ans
	#no_paths=[]
	#for n in range(7):
#		list=pascal(n)
#		if len(list)%2==1:
#			no_paths.append(list[(len(list)-1)/2])
	#print no_paths
	#n=3
	#path=start(n)
	#paths.append(path)
	#while reverse(paths[-1])!=paths[0]:
	#	flip_iteration(paths[-1],n)
	#print len(paths)
	#for i in paths:
#		print i:w

