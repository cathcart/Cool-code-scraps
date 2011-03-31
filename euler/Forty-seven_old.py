from math import sqrt
from math import log

divisors={}

def func_primes(end):  
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


'''def func_primes(end):
        #write it for primes first
        lng=((end/2)-1+end%2)
        sieve=[True]*(end+1)
        for i in range(2,int(sqrt(end))):
                if not sieve[i]:
                        continue

                for j in range(i**2,end,i):
                        sieve[j]=False	
		#for j in range(1,int(log(end)/log(i))+1):
		#	sieve[i**j]=False
	return sieve'''
	#for x in range(2,end):
#		if sieve[x]:
#			yield x

'''
def func_primes(end):  
  lng = ((end/2)-1+end%2)  
  sieve = [True]*(lng+1)  

  for i in range(int(sqrt(end)) >> 1):  
    if not sieve[i]: continue  
    for j in range( (i*(i + 3) << 1) + 3, lng, (i << 1) + 3):  
      sieve[j] = False  
  primes = [2]  
  for i in range(lng):
	 if sieve[i]:
		yield (i << 1) + 3
'''
  #primes.extend([(i << 1) + 3 for i in range(lng) if sieve[i]])  
  #return primes

def all(list):
	f=1
	for i in list:
		f*=i
	return f

def T(x,i):
	l=log(i)/log(x)
	if int(l)==l:
		return False
	else:
		return True

def tmp():
	from math import log
	end=10**4
	primes=func_primes(end)
	#sieve=func_primes(end)
	#primes=[x for x in range(2,end) if sieve[x]]
	#list=[x for x in range(2,end) if x not in primes]#not primes
	#list2=[i for i in list if all([T(x,i) for x in primes if x<i])]#not primes or multiple of primes
	
	#list2=[i for i in [x for x in range(2,end) if x not in func_primes(end)] if all([T(x,i) for x in func_primes(end) if x<i])]
	list2=[]#faster
	for num in range(2,end):
		if num not in primes and all([T(x,num) for x in primes if x<num]):
			list2.append(num)
			
	#create a dic that will hold all the numbers (of list2 )and their distinct prime factors
	N=4#this is the number of factors we require
	dic={}
	for i in list2:
		num=i
		#possible=[x for x in primes if x<i/N]
		possible=[]
		for x in primes:
			if x<i/N:
				possible.append(x)
			
		ans=[]
		while num !=1:
			if num not in list2 or primes:
				break
			for prime in reversed(possible):
				if num%prime==0:
					if prime not in ans:
						ans.append(prime)
					num/=prime
		dic[i]=ans
	return	
	d_len=len(dic.keys())
	list=[x for x in dic.keys() if len(dic[x])==N]
	#print list
	for i in range(len(list)):
		ans=[list[i],]
		k=1
		while i+k<len(list):
			if list[i+k]-list[i+k-1]==1:
				ans.append(list[i+k])
				k+=1
			else:
				break
		if len(ans)==N:
			print ans
			break



def temp():
	end=20
	primes=func_primes(end)

	def factors(number):
		if number==1:
			return 1
		for x in func_primes(number):
			if number%x==0:
				return [x].extend(factors(number/x))

	print factors(6)

	def comp(end):
		N=2
		dic={}
		for num in range(2,end):
			if num not in func_primes(end):
				#num is not a prime
				#get all possible numbers that could be factors
				number=num
				factors=[]
				while number!=1:
					for x in func_primes(number/(N-len(factors))):
						if number%x==0:
							factors.append(x)
							number/=x
							break
						else:
							pass
						break
				dic[num]=factors
		return dic

	#print comp(20)
def new():
	#sieve out all the primes and prime powers
	N=11
	sieve=func_primes(N)
	print sieve
	for i in range(2,N):
		if sieve[i]:
			print i
			for j in range(1,int(log(N)/log(i))):
				print "\t %d" %i**j

if __name__=="__main__":
	new()
