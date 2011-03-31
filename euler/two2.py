#def fib():
#    a, b = 0, 1
#    while True:
#        yield a
#        a, b = b, a + b

#for i in fib():
#	if i>=4000000:
#		break
#	if i%2==0:
#		sum+=i
#print sum

sum=0
a,b=0,1
#while a<4000000:
while a<10:
	if a%2==0:
		sum+=a
	a,b=b,a+b
print sum
