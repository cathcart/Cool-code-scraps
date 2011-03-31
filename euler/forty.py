def ans():
	num="1"
	i=0
	while len(num)<=1000000:
		i+=1
		num+=str(i)
#	for i in range(1,1000001):#slower
#		num+=str(i)
#	num="".join([str(x) for x in xrange(1,1000001)])#slowest
	q=[int(num[pow(10,i)]) for i in range(6)]
	s=1
	for i in q:
		s*=i
	print s


ans()
