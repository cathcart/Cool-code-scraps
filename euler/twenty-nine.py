nums=range(2,101)
list=[]
for a in nums:
	for b in nums:
		ans=pow(a,b)
		if ans not in list:
			list.append(ans)
print len(list)
