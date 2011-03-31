#global
fib_dic={1:1,2:1}
def fib(n):
	if n ==0 or n == 1:
		return n
	else:
		return fib(n-1)+fib(n-2)
def fib2(n):
	if n not in fib_dic:
		fib_dic[n]=fib2(n-1)+fib2(n-2)
	return fib_dic[n]

if __name__=="__main__":
	for k in range(1,5):
		N=100000*k
		for i in range(1000+100000*(k-1),N,500):
			fib2(i)
		print fib2(N)	
	#for i in range(100,400,50):
#		fib2(i)
	#sum=0
	#for i in fib_dic.keys():
#		if i%2 == 0:
#			sum+=fib_dic[i]
#	print i
