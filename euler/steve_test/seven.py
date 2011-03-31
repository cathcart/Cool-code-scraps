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

import time
N=87178291199
start=time.time()
print sieveOfErat(N+1)[-1]
print time.time()-start
