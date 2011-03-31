from math import sqrt
from math import log
import time

def primes(end):  
  if end < 2: return []  
  lng = ((end/2)-1+end%2)  
  sieve = [True]*(lng+1)  
  for i in range(int(sqrt(end >> 1))):  
    if not sieve[i]: continue  
    for j in range( (i*(i + 3) << 1) + 3, lng, (i << 1) + 3):  
      sieve[j] = False  
  primes = [2]  
  primes.extend([(i << 1) + 3 for i in range(lng) if sieve[i]])  

  return primes

def repeate_num(N):
	"returns the maximum repeated digit, or a negtive number if no repeats"
	l=[int(x) for x in str(N)]
	d={}
	for i in l:
		d[i]=l.count(i)
	m=max(d.values())
	if m>1:
		#return repeated num
		i=d.values().index(m)
		return d.keys()[i]
		print d
		print d.keys().index(d.values().index(max(d.values())))
	else:
		return -1

def family(num,N):
	"returns the family of numbers with base num and repeat digit N"
	num=str(num)
	N=str(N)
	return map(lambda x: int(num.replace(N,str(x))),range(10))

def ans():
	N=999999
	family_num=8
	prime_list=[x for x in primes(N)]
	b=set(prime_list)
	for n in prime_list:
		t=repeate_num(n)
		if t>0:
			a=set(family(n,t))
			c=a&b
			if len(c)>family_num-1 and sum([len(str(x)) for x in c])%family_num==0:
				return sorted(list(c))
				
				
if __name__=="__main__":
	print ans()	
