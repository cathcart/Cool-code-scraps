from math import sqrt
from math import log


def primes(end):  
  if end < 2: return []  
  lng = ((end/2)-1+end%2)  
  sieve = [True]*(lng+1)  
  for i in range(int(sqrt(end)) >> 1):  
    if not sieve[i]: continue  
    for j in range( (i*(i + 3) << 1) + 3, lng, (i << 1) + 3):  
      sieve[j] = False  
  primes = [2]  
  primes.extend([(i << 1) + 3 for i in range(lng) if sieve[i]])  

  return primes

def factors(N,prime):
	if N in prime:
		return [N]#N is a prime number, no factors (stop wasting my time)
	else:
		for num in prime:
			if N%num==0:
				return [num] +factors(N/num,prime)
	
def ans():
	N=150000
	LENGTH=4
	prime_list=primes(N)
	primes_powers=[i**j for i in prime_list for j in range(2,int(log(N)/log(i)+1))]
	ans=list(set(range(2,N))-set(prime_list)-set(primes_powers))

	for i in range(len(ans)-LENGTH-1):
		k=LENGTH-1
		s=0
		while k>0:
			s+=ans[i+k]-ans[i+k-1]
			k-=1
		if s==LENGTH-1:
			poss=[]
			for k in range(LENGTH):
				poss.append(ans[i+k])
			s2=0
			for num in poss:
				if len(set(factors(num,prime_list)))==LENGTH:
					s2+=1
				else:
					break
			if s2 == LENGTH:
				print poss
				break
def fast():
	max=150000
	n_factor=[]*max
	
	for i in range(2,max):
		if n_factor[i] == 0:
			for j in range(2*i,max,i):
				n_factor[j]+=1
	goal=[4]*4

	for i in range(2,max):
		if n_factor[i:i+4] == goal:
			print i
			break				
if __name__=="__main__":
        ans()

