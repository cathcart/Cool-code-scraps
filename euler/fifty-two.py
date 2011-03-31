def num_split(n):
	"splits n into its digits"
	return sorted([x for x in str(n)])

def test(n):
	"combined test function"
	return reduce(lambda x,y:x*y,map(lambda x:[False,True][num_split(n)==num_split(x*n)],[2,3,4,5,6]))

def ans():
	for i in xrange(1,999999):
		if test(i)==1:	
			print i
			break
	
if __name__=="__main__":
	#print map(lambda x:['small','big'][x>5],range(11))
	#print reduce(lambda x,y:x*y,[0,1,1])
	#print test(125874)
	ans()
