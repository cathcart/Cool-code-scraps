from math import sqrt
#this is actually quite slow. i'm sure further analysis could reveal the solution quicker than by optimisation
def comp(end):
	#write it for primes first
	lng=((end/2)-1+end%2)
	sieve=[True]*(end+1)
	for i in range(2,int(sqrt(end))):
		if not sieve[i]:
			continue

		for j in range(i**2,end,i):
			sieve[j]=False
	return sieve
	return [i for i in range(2,end+1) if not sieve[i]]

def test(N,prime):
	p=[i for i in prime if i<N]
	n=[(N-i)/2 for i in p]
	n_=[sqrt(i) for i in n]
	for i in range(len(n)):
		if int(n_[i])==n_[i]:
			return True
	return False

def ans():
	end=10000
	sieve=comp(end)
	composite=[i for i in range(3,end+1) if not sieve[i] and i%2!=0]
	prime=[i for i in range(3,end+1) if sieve[i]] 

	for i in composite:
		if not test(i,prime):
			print i
if __name__=="__main__":
	ans()
