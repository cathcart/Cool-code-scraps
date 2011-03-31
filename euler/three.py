import math

primes=[]

def prime(N):
	'''sieve of eratosth algorithm to find primes up to N'''
	list=range(2,N+1)
	while len(list)>1:#loop through the list
		i=list[0]
		primes.append(i)
		k=1
		while k*i<=list[-1]:
			try:
				list.remove(k*i)
			except:
				pass#element likely to have already have been removed, not concerned
			k+=1
	primes.append(list[0])
	return list


if __name__=="__main__":
	prime(20)#16000#double the size of the sample number of primes until the ans no longer changeS
	print primes
	number=600851475143
	#number=13195

	for i in primes:
		if number%i == 0:
			print i
