num=str(pow(2,1000))

sum=0
for i in num:
	sum+=int(i)
print sum

#nice one liner
#sum(int(digit) for digit in str(2**1000))

