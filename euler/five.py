import sys
'''
the smallest number that can be divided by each of the numbers from 1 to 10 with out any remainder must be have all of the numbers 1 to 10 as factors, or better yet it must have all the prime numbers from 1 to 10 as prime factors.
with this in mind the prime numbers from 1 to 10 are:
2,3,5,7
giving 
2*3*5*7=210
we can see here that of the other numbers not given here 4,6 and 10 will divide evenly into this number but 8 and 9 will not.
and 2 and 3 are factors of 8 and 9 we can rewrite this as:
8*9*5*7=2520

expanding this idea now to cover the prime numbers from 1 to 20 gives:
2, 3, 5, 7, 11, 13, 17 and 19
giving:
2*3*5*7*11*13*17*19=9699690
if we now check this number for the remaining numbers and replace the prime factors in this equation with those ones that don't divide into 9699690 we'll arrive at the right number :)
'''

list=range(2,21)
list2=[2, 3, 5, 7, 11, 13, 17, 19]
for i in list2:
	if i in list:
		list.remove(i)
print list

#check list to see which divide into 9699690
#num=9699690
num=465585120
num=int(sys.argv[1])
for i in list:
	print i,
	if num%i==0:
		print "\tyes"
	else:
		print "\tno"
#list.reverse()
#list2.reverse()
#for i in list:
#	for k in list2:
#		if i%k==0:
#			print "%d is a prime factor of %d" % (k,i)
'''
The correct answer is 232792560. it is 16*9*5*7*11*13*17*19
''' 
