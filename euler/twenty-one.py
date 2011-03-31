from math import sqrt
import time
def d(n):#sum of the proper divisors of n (numbers less than n which divide evenly into n).

	sieve=[True]*n
	sum=0
	for i in range(2,int(sqrt(n))+1):
		if sieve[i]:
			if n%i==0:#proper divisor
				sum+=i+n/i
				sieve[i]=False
				sieve[n/i]=False	
		
	return sum+1#don't forget 1 also divides into it :)

def amicable_sum(N):
	#sum of the amicable numbers under 10000
	sieve=[True]*N

	sum=0
	for i in range(N):
		if sieve[i]:
			possible_pair=d(i)
			if i!=possible_pair and d(possible_pair)==i:
				#amicable pair
				print "%d %d" %(i, possible_pair)
				sum+=i+possible_pair
				sieve[i]=False
				sieve[possible_pair]=False
	return sum
if __name__=="__main__":
	start=time.time()
	print amicable_sum(10000)
	print "Run Time =" +str(time.time()-start)	
