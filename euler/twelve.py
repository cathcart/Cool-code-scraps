import math
#this could be sped up by using a dic#this won't actually help
triangular={}
def trig(N):
	if N not in triangular:
		sum=0
		for i in range(1,N+1):
			sum+=i
		triangular[N]=sum
	return triangular[N]

#for i in range(1,11):
#	print "%d %d" %(i,trig(i))

def fact(N):
	factors=[]
	for i in range(1,int(math.sqrt(N))):
		if N%i==0:
			factors.append(i)
			factors.append(N/i)
	return factors

if __name__=="__main__":
	N=1
	while len(fact(trig(N)))<500:
		N+=1
print trig(N)
#print fact(28)
