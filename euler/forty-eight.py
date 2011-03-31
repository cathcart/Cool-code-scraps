dic={0:1,1:1,2:2}
def fact(n):
        if n not in dic.keys():
                dic[n]=n*fact(n-1)
        return dic[n]

def next_power(n):
	s=0
	for k in range(n+1):
		s+=(fact(n)/(fact(k)*fact(n-k)))*n**k
	return (n+1)*s

def ans_slow():
	s=0
	for i in range(1,1001):
		s+=pow(i,i)
		#print i,s
	return s



if __name__=="__main__":
	t=str(ans_slow())
	print t[-10:]
