from math import sqrt

def P(N):
	return (N)*(3*N-1)/2

def pent_test(N):
	try:
		ans1=(1+sqrt(24*N+1))/6
	except:
		ans1=0.3
	#try:
	#	ans2=(1-sqrt(24*N+1))/6
	#except:
	#	ans2=0.3
	if int(ans1)==ans1:#actually only need this one
		return True
	#if int(ans2)==ans2:
	#	return False
	return False

def ans():
	N=2000
	for a in range(1,N):
		for b in range(1,N):
			if b!=a:
				A=P(a)
				B=P(b)
				if pent_test(A+B):
					if pent_test(2*A+B):
						print [A+B,A],[2*A+B,B]
def fast():
	def test(N):
		ans1=(1+sqrt(24*N+1))/6
		if int(ans1)==ans1:
                	return True

	list=[(N)*(3*N-1)/2 for N in range(1,2000)]
	for a in list:
		for b in list:
			if test(a+b):
				if test(2*a+b):
					return [a+b,a],[2*a+b,b]
if __name__=="__main__":
	#ans()
	print fast()
