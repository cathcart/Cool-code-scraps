def collatz(n):
	if n%2==0:
		return n/2
	else:
		return 3*n+1
dic={2:2}
def dic_cal(n):
	if n not in dic:
		iter=collatz(n)
		if iter!=1:
			dic[n]=1+dic_cal(iter)
	return dic[n]
max_chain=0
max_num=0
for i in range(1,1000000):
	if dic_cal(i)>max_chain:
		max_num=i
		max_chain=dic_cal(i)
print max_chain
print max_num
