dic={0:1,1:1,2:2}
def fact(n):
	if n not in dic.keys():
		dic[n]=n*fact(n-1)
	return dic[n]
def test(a):
	s=0
	for i in str(a):
		s+=fact(int(i))
	if s==a:
		return 1
	else:
		return 0
def my_ans():
        s=0
        for i in xrange(3,9999999):
                if test(i):
                        print i
                        s+=i
        print s

if __name__=="__main__":
	s=0
	for n in xrange(3,9999999):
		if n==sum([fact(int(d)) for d in str(n)]):
			s+=n
	print s
