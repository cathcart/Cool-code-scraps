from math import sqrt
from math import log
import time

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
def int_to_list(i):
	return [int(k) for k in str(i)]

def test(list):
	if set(int_to_list(list[0]))==set(int_to_list(list[1])) and set(int_to_list(list[0]))==set(int_to_list(list[2])):
		return True
	else:
		return False

def ans():
	a=3330
	list=[i for i in primes(10000) if i > 999]
	for i in list:
		if i+a in list and i+2*a in list:
			t=[i,i+a,i+2*a]
			if test(t):
				print t

if __name__=="__main__":
	start=time.time()
	ans()
	print time.time()-start
