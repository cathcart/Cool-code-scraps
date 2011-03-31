from math import sqrt
def rotate(num):
	list=[x for x in str(num)]
		
	for i in list:
		if len(list)>1:
			if i not in [1,3,7,9]:
				yield 2
		t=list[0]
		list.remove(t)
		list.append(t)
		yield int("".join(list))
	
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

def ans():
	list=[1,3,9,7]
	s=0
	N=1000000
	primes=sieveOfErat(N)
	for num in primes:
		if num>10:
			if int(str(num)[-1]) not in list:
				break
		t=1
		for i in rotate(num):
			if i not in primes:
				t=0
				break
		if t==1:
			s+=1
	print s
if __name__=="__main__":
	ans()
