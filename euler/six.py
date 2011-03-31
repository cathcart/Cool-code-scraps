def square(list):
	for i in list:
		yield i*i

if __name__=="__main__":
	n=100
	list=range(n+1)
	sum=0
	square_sum=0
	for i in square(list):
		square_sum+=i
	for i in list:
		sum+=i
	print abs(square_sum-sum*sum)
