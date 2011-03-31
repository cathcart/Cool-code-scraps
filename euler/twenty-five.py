from math import sqrt
fib_dic={1:1,2:1}
#global
n1=1
n2=1

def fib2(n):
        if n not in fib_dic:
                fib_dic[n]=fib2(n-1)+fib2(n-2)
        return fib_dic[n]
def fib():
	global n1
	global n2
	n_n2=n1+n2
	n1=n2
	n2=n_n2
	return n2

def fib3(n):
	phi=float((1+sqrt(5))/2.0)
	try:
		one=pow(phi,n)
	except Exception,e:
		print n
		print e
	two=pow(1-phi,n)
	return int(one-two/sqrt(5))
	return int((pow(phi,n)-pow((-1/phi),n))/sqrt(5))

if  __name__=="__main__":
	fi=fib()
	i=3
	while len(str(fi))<1000:
		fi=fib()
		i+=1
	print "The %d th fibonacci number has length %d " %(i,len(str(fi)))
