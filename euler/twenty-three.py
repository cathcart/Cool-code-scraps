import time
from math import sqrt

def d2(n):#much much faster
  s = 1
  t = n ** .5
  for i in xrange(2, int(t)+1):
    if n % i == 0: s += i + n / i
  if t == int(t): s -= t#if sqrt(n) != integer it's not a proper divisor and so must be removed, accidently added
  return s

def d(n):#sum of the proper divisors of n (numbers less than n which divide evenly into n).
        sieve=[True]*n
        for i in xrange(2,int(sqrt(n))+1):
                if sieve[i]:
                        if n%i==0:#proper divisor
                                sieve[i]=False
                                sieve[n/i]=False        
        
	return sum([i for i in range(n) if sieve[i]==False])+1#don't forget 1 is also a divisor 

def abundant_numbers(N):
#Every proper multiple of a perfect number, and every multiple of an abundant number, is abundant
	sieve=[False]*N
        for i in range(6,N):
		if not sieve[i]:# and i not in primes:
			prime_sum=d2(i)
        		if prime_sum>i:
				for j in range(i,N,i):
					if j<N:
		         			sieve[j]=True
			if prime_sum==i:
                                for j in range(2*i,N,i):
                                        if j<N:
                                                sieve[j]=True

	return [i for i in range(12,N) if sieve[i]]

def abu(N):#too slow
	list=[]
	for i in range(12,N):
		if i not in list:
			if d(i)>i:
				list.append(range(i,N,i))
	return list	

if __name__=="__main__":
	#actually we can first strip out all the primes in this range
	#don't bother
	start=time.time()
	N=28123
	#N=50
	#list=abundant_numbers(N)
	list=abu(N)
	total_sum=[x+i for i in list for x in list]
	not_wanted=set(total_sum)
	total=set(range(1,N))
	print sum(total-not_wanted)
	print "Run Time: " +str(time.time()-start)
