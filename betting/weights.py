file1=open("06_weights")
file2=open("10_unique")

new=[0,0,0]

for item_06 in file1:
	file2=open("10_weights")
	for item_10 in file2:
		items_06=item_06.split()
		item_10s=item_10.split()

		if items_06[0]==item_10s[0]:
			new=[items_06[0],(float(items_06[1])+float(item_10s[1]))/2.0,(float(items_06[2])+float(item_10s[2]))/2.0]
			print new[0]," ",new[1]," ",new[2]	
