import string

def frac(a,b):
	for i in range(len(a)):
		r=string.find(b,a[i])
		if r>=0:
			#print "%s/%s"%(a[(i+1)%2],b[(r+1)%2])
			return [int(a[(i+1)%2]),int(b[(r+1)%2])]
	return [0]

s=[1,1]
for i in xrange(12,100):
	for j in xrange(11,i):
		r=frac(str(j),str(i))
		if len(r)==2 and 0 not in r:
			if j/float(i)==r[0]/float(r[1]) and j/r[0]!=10:
				print "%d/%d %d/%d" %(j,i,r[0],r[1])
				s[0]*=r[0]
				s[1]*=r[1]
				
print s
