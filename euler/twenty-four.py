def lowest_num(n):
	nums=range(n)
	num=[]
	for i in range(n):
		num.append(min(nums))
		nums.remove(min(nums))
	return num

def next_num(num):
	new=num[:]
	k=num.index(max(num))
	t=num[k-1]
	new[k-1]=max(num)
	new[k]=t
	return new

combinations={0:[[0]]}

def it_combinations(N):
	list=[]
	for combination in combinations[N-2]:
		for i in range(N):
			if i==0:
				list.append([N-1]+combination)
			elif i==N-1:
				list.append(combination+[N-1])
			else:
				list.append(combination[:i]+[N-1]+combination[i:])
	combinations[N-1]=list

def all_combinations(N):
	list=[range(N)]
	for num in list:
		for j in range(N):
			for i in range(N):
				k=num[i]
				new=num[:]
				new[num.index(j)]=k
				new[i]=j
				if new not in list:
					list.append(new)
	return list
if __name__=="__main__":
	import time
	start=time.time()
	N=11
	for i in range(2,N):
		it_combinations(i)
	ans=sorted(combinations[N-2])[1000000-1]
	for i in ans:
		print i,
	print
	print "Time to complete generating the numbers: " +str(time.time()-start)
	
