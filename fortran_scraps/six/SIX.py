
if __name__=="__main__":
	N=100
	print sum(map(lambda x: x*x ,range(1,N+1)))-sum([x for x in range(1,N+1)])**2
