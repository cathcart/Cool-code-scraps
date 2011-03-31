def is_palin(n):
	num=str(n)
	if n%2:
		truth=1
		for i in range(len(num)/2):
			if num[0+i]!=num[-1-i]:
				truth=0
				break
	else:
		truth=1
		for i in range((len(num)-1)/2):
                        if num[0+i]!=num[-1-i]:
                                truth=0
                                break
	return truth

#generate the products in sequence
a=range(100,999)
a.reverse()
list=[]
for i in a:
	for k in a:
		if i*k%11==0:
			if is_palin(i*k)==1:
				list.append(i*k)
print sorted(list)[-1]
'''
palindrome=abccba
100000a + 10000b + 1000c + 100c + 10b + a

And then:

100001a + 10010b + 1100c

Factoring out 11, you get:

11(9091a + 910b + 100c)
we can then check that the number is divisible by 11 first, to reduce the number of numbers we need to brute force :)
'''
