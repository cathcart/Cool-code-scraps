def Lychrel_test(N):
        c=0
	a=int(str(N)[::-1])
	N+=a
        while c<51:
                a=int(str(N)[::-1])
                c+=1
                if N==a:
                	return False#N is palindromic 
		N+=a
        return True#N is Lychrel

def next_test(N,x):
	return reduce(lambda x,y:x+int(str(y)[::-1]),[N]*x)

def test_data(N):
	return map(lambda x:next_test(N,x),range(1,50))

def test(N):

	print filter(lambda x:x==int(str(x)[::-1]),test_data(N))


def ans():
	print len(filter(lambda x:test(x),range(1,10001)))

if __name__=="__main__":
	print test(196)
	#ans()
