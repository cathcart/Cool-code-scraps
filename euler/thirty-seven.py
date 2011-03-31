from math import sqrt
from math import log10
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


def test(num,primes):
	length=range(len(str(num)))
	for i in length:#left remove
		if int(str(num)[i::]) not in primes:
			return False
	length=range(1,len(str(num))+1)
	length.reverse
	for i in length:#right remove
		if int(str(num)[:i]) not in primes:
			return False
	return True

def test2(num,primes):#doesn't seem to work??
	right=num
	left=num

	while right/10>0:
		right/=10
		if right not in primes:
			return False
	while left/10>0:
		left=left%int(log10(left))
		if left not in primes:
			return False
	return True
			

def ans():
	N=999999
	s=0
	list=[]
	primes=sieveOfErat(N)
	for num in primes:
		if test(num,primes) and num>10:
			list.append(num)
			s+=num
	print list
	print len(list)
	print s

if __name__=="__main__":
	ans()
