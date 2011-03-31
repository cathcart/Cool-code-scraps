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

def ans():
	
	dic={}
	N=10**6
	start=time.time()
	list=primes(N)
	print "Time to generate primes: " +str(time.time()-start)
	slist=[]
	i=0
	while sum(slist)<N:
		slist.append(list[i])
		i+=1
	length=len(slist)
	#print slist
	while length>3:
		for k in range(0,len(slist)-length):
			test_list=list[k:k+length]
			#print test_list, sum(test_list),len(test_list)
			t=sum(test_list)
			if t in list:
				dic[len(test_list)]=t
		length-=1
		if len(dic.keys())>0 and max(dic.keys())>length:#this makes it much faster :)
			break

	t=max(dic.keys())
	print t,dic[t]

if __name__=="__main__":
	start=time.time()
	ans()
	print time.time()-start
