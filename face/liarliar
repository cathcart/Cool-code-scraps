#!/usr/bin/python
import sys

#compile results
#pick name with most ammount of convictions
#group everyone into those that agree(same predictions) with this person and those that disagree(call selected person a liar)

def get_input():
	dic={}
	count={}
	file_in=sys.argv[1]
	for line in open(file_in):
		t=line.strip().strip("\n")
		items=t.split()
		if len(items)==2:
			name=items[0]
			dic[name]=[]
		if len(items)==1 and not items[0].isdigit():
			dic[name].append(items[0])
			if items[0] in count.keys():
				count[items[0]]=count[items[0]]+1
			else:
				count[items[0]]=1
	c=count.values()
	m=max(c)
	v=c.index(m)
	i=c.index(v)
	k=count.keys()
	n=k[i]#this is the most accused person
	#print dic
	return [n,dic]


def lies(n,dic):
	#get those that disagree with n
	d=0
	for name in dic.keys():
		if n in dic[name]:
			d+=1
			#print "disagreer", name
		#else:
			#print "agreer", name
	N=len(dic.keys())
	if N-d>d:
		print N-d,d
	else:
		print d,N-d

if __name__=="__main__":
	[n,dic]=get_input()
	lies(n,dic)
