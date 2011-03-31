# score is determined by
#   1. Replacing any single letter with another letter.
#   2. Adding a single letter in any position.
#   3. Removing any single letter.
#this is just the Levenshtein distance

import sys

class Matrix:
    def __init__(self,rows,cols):
	self.rows=rows
	self.cols=cols
	self.matrix=[[0 for x in range(cols)] for y in range(rows)]
    
    def __repr__(self):
	#return repr(self.matrix)
	 outStr = ""
         for i in range(self.rows):
             outStr += '%s\n' % (self.matrix[i])
         return outStr

    def valueset(self,row,col,v):
	self.matrix[row][col]=v	

    def valueget(self,row,col):
	return self.matrix[row][col]
	
def distance(word,actual):
	n=len(word)
	m=len(actual)
	if n==0 or m==0:
		print "ERROR"
		print [word,actual]
		sys.exit()
	t=Matrix(m+1,n+1)
	#initialise the first column and row of t
	for i in range(1,n+1):#initialise row 0
		t.valueset(0,i,i)
	for j in range(1,m+1):#initialise column 0
		t.valueset(j,0,j)
	for i in range(1,m+1):
		for j in range(1,n+1):
			if word[j-1]==actual[i-1]:
				cost=0
			else:
				cost=1
			required_value=min([t.valueget(i-1,j)+1,t.valueget(i,j-1)+1,t.valueget(i-1,j-1)+cost])
			t.valueset(i,j,required_value)
	return t.valueget(m,n)	

#get wordlist
def get_wordlist():
	dic={}
	file="/var/tmp/twl06.txt"
	file="wordlist_T"#remove this later
	t=open(file).read().lower()
	s=t.split("\r\n")
	for line in s:
		if len(line) not in dic.keys():
			dic[len(line)]=[line]
		else:
			dic[len(line)]=dic[len(line)]+[line]
	return dic
def temp_ans():
	word="tihs"
	actual="this"
	dic=get_wordlist()
	print "dictionary imported"
	#short_list=dic[len(word)]
	short_list=dic.values()
	print "short list created"
	min_value=[99999,"crap"]
	word_set=set(word)
	for test in short_list:
		if word_set==set(test):
			x=distance(word,test)
			print test,x
			if x<min_value[0]:
				min_value=[x,test]
	print min_value


if __name__=="__main__":
	word="tihs"
	dic=get_wordlist()
	print "got word list ok"
	for test_list in dic.values():
		for test_word in test_list:
			if test_word!="":
				print distance(word,test_word),
				print test_word
