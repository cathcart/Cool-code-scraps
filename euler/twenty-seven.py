# -*- coding: utf-8 -*-  
'''
Considering quadratics of the form:
    n**2 + an + b, where |a| < 1000 and |b| < 1000
    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
--------------------------------------------------------
to get the n=0 prime value b must be a prime. Therefore we can limit our search for b to all positive primes less than 1,000 (i assume primes can only be positive, negative ones don't really make that much sensei)
'''

from math import sqrt
def sieveOfErat(end):
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

def length_of_consequative_primes(a,b,primes):
	n=0
	while n**2+a*n+b in primes:
		n+=1
	return n
def roots(a,b):
	if a**2<4*b:
		return "imaginary"
	return [(-a+sqrt(a**2-4*b))/2,(-a-sqrt(a**2-4*b))/2]

if __name__=="__main__":
	max=[0,0,0]#length,a,b
	N=1000
	primes=sieveOfErat(1000000)
	primes_list=[]
	for i in primes:
		if i<1000:
			primes_list.append(i)
			primes_list.append(-i)
		else:
			break
	print len(primes_list)
	for b in primes_list:
		if b>0:
			for a in primes_list+[-1*x for x in primes_list]:
				length=length_of_consequative_primes(a,b,primes)
                        	#print [length,a,b],
				#print roots(a,b)
				if length>max[0]:
                        		       max=[length,a,b]
	print max	
