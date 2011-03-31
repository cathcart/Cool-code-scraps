def func(n):#tried to work out squaring numbers with bit shifting....doesn't seem to work
	if n%2==0:
		#even
		return (n<<n/2)
	else:
		#odd
		return (n<<n/2)+n<<(n-1)%2
import sys
for c in range(1,1000):
	for b in range(1,c):
		for a in range(1,b):
			if (a*a+b*b==c*c) and a+b+c==1000:
				print "%d" %(a*b*c)
				sys.exit()
