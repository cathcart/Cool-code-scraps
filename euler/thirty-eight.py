'''
#start 0 at far right digit
4321

4312 #flip [1,0]
4231 #flip [2,1]
4213 #flip [2,1],[1,0]
4132 #flip [3,1],[
4123
'''
'''
import string
def pandigital(num,N):
	
	list=range(1,N/2+1)
	for i in str(num):
		try:
			list.remove(int(i))
			list.remove(N+1-int(i))
		except:
			if string.count(str(num),i)>1 or string.count(str(num),str(N+1-int(i)))>1:
				return False
	if len(list)==0:
		return True
	else:
		return False

def fast_pan(num,N):
	s=set(range(1,N+1))
	if set([int(i) for i in str(num)])==s:
		return True
	else:
		return False

def pan_gen(N):
	low=123456789
	high=987654321
	for num in reversed(xrange(low,high)):
		if fast_pan(num,N):
			yield num
#	while high>low:
#		if fast_pan(high,N):		
#			yield high
#		high-=1

def split(num,n):
	i=1
	for i in range(1,len(str(num))):
		t=int(str(num)[-i:])
		if t/float(n)==t/n and int(str(num)[:len(str(t/n))])==t/n:
			list=[t/n*x for x in range(1,n+1)]
			if num==int("".join([str(x) for x in list])):
				print "".join([str(x) for x in list]),
				print num
				return True
	return False

def pan_test(num):
	i=2
        while split(num,i)==False:
                i+=1
                if i>9:
                        return False
	return True

def num_smaller():
	num=987654321
	while num>123456789:
		for i in [9,81,18,81]:
			num-=i
			yield num
def num_smaller2():
	num=987654321
	while num>123456789:
		num-=1
		yield num

def ans():
	#num=192384576
	#num=918273645
	#num=987654321
	for num in num_smaller2():
		if num%9==0:#quick test for pandigit
			if fast_pan(num,9):
				print "Testing: "+str(num)
				if pan_test(num):
					print num
					break
'''
def fast_ans(x):
	#while this returns false return increase x
	num=str(x)
	i=1
	while 1:
		len_num=len(num)
		if len_num<9:
			i+=1
			num+=str(x*i)
		elif len_num==9 and set(num)==set('123456789'):
				return int(num)
		else:
			return False
def foo(N):
	for x in xrange(1,N):
		ans=fast_ans(x)
		if ans!=False:
			yield ans

if __name__=="__main__":
	print max(foo(10000))
	#ans()

'''
from itertools import count, imap
def ispandigital(seed):
   digits = str( seed)
   for i in count(2):#count like range with inf upper limit, can also define steps, even fractional steps
      ndig = len( digits)
      if ndig < 9: digits += str( seed * i)
      elif ndig == 9 and set( digits) == set( '123456789'):
         return int( digits)
      else: return False


print max( imap( ispandigital, xrange( 1, 10000)))
'''
