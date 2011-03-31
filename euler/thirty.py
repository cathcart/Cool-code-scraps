nums=range(4150,999999)
'''
no 7 digit number or higher can be true since
7*9^5<<9999999
'''
list=[]
for num in nums:
	s=0
	num=str(num)
	for digit in num:
		s+=pow(int(digit),5)
		if s>num:
			break
	if s==int(num):
		list.append(int(num))
print list
print sum(list)
