dic={0:1,1:1,2:2}
def fac(n):
        if n not in dic.keys():
                dic[n]=n*fac(n-1)
        return dic[n]

def C(n,r):
	return fac(n)/(fac(r)*fac(n-r))

def ans2():
	required_num=0
        l=[1,1]#for N=1
	N=1
	while N<100:
        	N=len(l)
        	l_=[int(((float(N))/float((N-x)))*l[x]) for x in range(N)]+[1]#for N=2
		l=l_[:]
		required_num+=len(filter(lambda x:x>1000000,l))
		#print N,l
	print required_num  

def ans():
	t_larger=0
	N=1
	while N<24:
		larger=0
		for i in range(1,(N)/2):
			if C(N,i)>1000000:
				larger+=1
		larger*=2
		larger+=1
		t_larger+=larger
	print t_larger

if __name__=="__main__":
	ans2()	
