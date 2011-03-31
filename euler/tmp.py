in_put=open("tmp")

for line in in_put:
	items=line.split()
	print "%s %s" %(items[0],len(items[1])-2)
