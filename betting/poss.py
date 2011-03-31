import sys
import math

#mean1=float(sys.argv[1])
#mean2=float(sys.argv[2])

def fac(n):
	if n==1 or n==0:
		return 1
	else:
		return n*fac(n-1)

def poisson(n,mean):
	return ((pow(mean,n))*(math.exp(-mean)))/fac(n)

def result(mean1,mean2):
	max=0
	for i in range(5):
		for j in range(5):
		#	print i,
		#	print j,
			prob=poisson(i,mean1)*poisson(j,mean2),
		#	print prob
			if prob>max:
				max=prob
				result=[i,j]
		#print
	return result

#print "result:",
#print result

#print 1/max[0]

