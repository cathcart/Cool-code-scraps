import math
def fast_pan(num,N):
        s=set(range(N))
        if set([int(i) for i in str(num)])==s:
                return True
        else:
                return False

def test(n):
	num=str(n)
	if int(num[1:4])%2==0 and int(num[2:5])%3==0 and int(num[3:6])%5==0 and int(num[4:7])%7==0 and int(num[5:8])%11==0 and int(num[6:9])%13==0 and int(num[7:10])%17==0:
		return True
def fast_test(n):
	num=str(n)
	for i in [17,13,11,7,5,3,2]:
		if int(num[-3:])%i!=0:
			return False
		num=num[:-1]
	return True

def final():
	num=NUMBER
	len_d=len(str(num))
	s=0
	while len_d==10:
		num+=17
		len_d=len(str(num))

		if int(str(num)[-4:-1])%13==0:
			if int(str(num)[-5:-2])%11==0:
				if fast_pan(num,10):
					if fast_test(num):
						s+=num
	print s
def my_SUM(num):
	if num/10==0:
		return num
	else:
		return my_SUM(sum([int(i) for i in str(num)]))
def list_ans():
	s=0
	divisors=[13,11,7,5,3,2]
	list=[]
	for d in divisors:
		list.append([str(i) for i in range(999) if i%d==0])
	for num in xrange(NUMBER,9876543210,17):
		str_num=str(num)
		length=len(str_num)
		for i in range(len(divisors)):
			if str_num[-4-i:length-i-1].lstrip('0') not in list[i]:
				break
		if i==len(divisors)-1:
			if fast_pan(num,10):
				print "\t %d" % num
				s+=num
	print s

def numbers(N):
	for x in xrange(999):
		if x%N==0:
			yield str(x)

def quick():
	for num in xrange(NUMBER,9876543210,17):
		str_num=str(num)
		if str_num[-4:-1] in numbers(13):
			if str_num[-5:-2] in numbers(11):
				if str_num[-6:-3] in numbers(7):
					if str_num[-5]=='5' or str_num[-5]=='0':
						if my_SUM(int(str_num[-8:-5])) in [3,6,9]:
							if str_num[3] in ['0','2','4','6','8']:
								if fast_pan(num,10):
									print num
			
	
def quick2():
	s=0
	for num in xrange(NUMBER,9876543210,17):
		str_num=str(num)
		if str_num[5]=='5':#d6
			if str_num[6] not in ['3','4','5']:#d7
				if str_num[7]!='0' or str_num[7]!='5':#d8
					if test(num):
						if fast_pan(num,10):
							print num
							s+=num
	print s
if __name__=="__main__":
	NUMBER=1406357289
	quick2()
