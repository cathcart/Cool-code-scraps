from math import sqrt
def pan_test(num,N):
        if set([int(i) for i in str(num)])==set(range(1,N+1)):
                return True
        else:
                return False

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

def new(N):
        max="".join([str(x) for x in range(1,N+1)])
        primes=sieveOfErat(int(max[::-1]))
        for i in primes:
                num_len=len(str(i))
                if num_len==N and pan_test(i,N):
                	yield i
                elif num_len>N:
                        return

def ans():
	print max(new(7))
def test():
	for N in range(4,9):
		print "%d %d" %(N,sum(range(N+1)))
if __name__=="__main__":
	test()
	#ans()
