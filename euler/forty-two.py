def data():
	words=[]
	for line in open("forty-two.dat"):
		items=line.split(",")
		for i in items:
			words.append(i.strip('"'))
	return words

def word_value(word):
	s="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	return sum([s.index(i)+1 for i in word])	

def tri_nums(n):
	for i in range(1,n+1):
		yield 0.5*i*(i+1)

def ans():
	words=data()
	s=0
	for word in words:
		if word_value(word) in tri_nums(26*len(word)):
			s+=1
	print s

if __name__=="__main__":
	ans()
