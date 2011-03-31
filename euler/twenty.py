def factorial(n):
	if n==0 or n==1:
		return 1
	else:
		return n*factorial(n-1)
num=str(factorial(100))
sum=0
for i in range(len(num)):
	sum+=int(num[i])
print sum
