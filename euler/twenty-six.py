def divide(a,b):
	if a<b:
		ans=[0,]
	else:
		ans=[int(a/b),]
	remainder=a%b
	digit_no=0
	seen={remainder:digit_no}
	while 1:
		remainder*=10
		ans.append(int(remainder/b))
		remainder%=b
		digit_no+=1
		if remainder not in seen.keys():
			seen[remainder]=digit_no
		else:
			length=digit_no-seen[remainder]
			break
	return length

if __name__=="__main__":
	max=[0,0]#length,num
	for i in range(2,1000):
		ans=divide(1,i)
		if ans>max[0]:
			max[0]=ans
			max[1]=i
	print max		
