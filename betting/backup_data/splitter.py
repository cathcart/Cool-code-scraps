infile=open('data')

n=0
outfile_name="out"+str(n)

print outfile_name

for line in infile:
	items=line.split()
	outfile=open(outfile_name,"a")
	outfile.write(line)
	if items[0]=="Group":
		outfile.close()
		n+=1
		outfile_name="out"+str(n)
		print outfile_name

 
