month_days=[31,28,31,30,31,30,31,31,30,30,31]#change this in leap years

count=0
day=0
#the year 1900 doesn't count
for month in month_days:
	if (day+month)%7!=0:
		day=(day+month)%7
	else:
		
	print day
	if day==6:
		count+=1	
count=0
for year in range(1901,2001):
	month_days[1]=28
	if year%100==0:#century
		#print "%d is a century" %year
		if year%400==0:#leap century
			#print "%d is a leap century" % year
			month_days[1]=29
	elif year%4==0:#leap year
		#print "%d is a leap year" % year
		month_days[1]=29
	
	for month in month_days:
		day=(day+month)%7
		if day==6:
			count+=1
#print count

