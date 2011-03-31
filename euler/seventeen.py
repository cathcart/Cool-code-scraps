dic={0:0,1:3,2:3,3:5,4:4,5:4,6:3,7:5,8:5,9:4,10:3,11:6,12:6,13:8,14:8,15:7,16:7,17:9,18:8,19:8,20:6,30:6,40:5,50:5,60:5,70:7,80:6,90:6}

def num_value(N):
	running_total=0
	#first take off the hundreds
	remainder=N%100
	if (N-remainder)/100!=0:#number of hundreds
		running_total+=dic[(N-remainder)/100]+7
		#if remainder is non zero add the "and"
		if remainder!=0:
			running_total+=3
	#if remainder is less than 21 we can just look it up
	if remainder<21:
		running_total+=dic[remainder]
	else:
		#repeat the hundreds process with tens
		tens_rem=remainder%10
		#add this tens
		running_total+=dic[(remainder-tens_rem)]+dic[tens_rem]
	return running_total
	
if __name__=="__main__":
	print num_value(760)
	sum=0
	n=5
	n=1000
	for i in range(1,n):

		sum+=num_value(i)
	sum+=11#add on "one thousand"
	print sum
