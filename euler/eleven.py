def read_input():
	input=open("eleven.dat")

	data=[]

	for line in input:
		items=line.split()
		row=[]
		for item in items:
			row.append(int(item))
		data.append(row)
	return data
def directions(start_i,start_j):
	products=[1,1,1,1,1,1,1,1]
        for i in range(4):
	        products[0]*=data[(start_j+i)%19][start_i]#up
	        products[1]*=data[(start_j-i)%19][start_i]#down
	        products[2]*=data[start_j][(start_i+i)%19]#right
		products[3]*=data[start_j][(start_i-i)%19]#left

		products[4]*=data[(start_j+i)%19][(start_i+i)%19]#ne
                products[5]*=data[(start_j-i)%19][(start_i+i)%19]#se
                products[6]*=data[(start_j-i)%19][(start_i-i)%19]#sw
                products[7]*=data[(start_j+i)%19][(start_i-i)%19]#nw

        return max(products)

if __name__=="__main__":
	max_value=0
	data=read_input()
	for i in range(20):
		for j in range(20):
			best_dir=directions(i,j)
			if best_dir>max_value:
				max_value=best_dir
	print max_value
