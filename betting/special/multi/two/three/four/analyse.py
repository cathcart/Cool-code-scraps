in_file=open("all")

hist={}

for i in in_file:
	try:
		hist[i]+=1
	except:
		hist[i]=0

print hist
