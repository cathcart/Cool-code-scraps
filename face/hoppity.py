#!/usr/bin/python
import sys
def get_input():
	file_in=sys.argv[1]
	for line in open(file_in):
		t=line.strip().strip("\n")
		if t!="":
			N=int(t)
	return N
def hop(N):
	for i in range(1,N+1):
		if i%3==0 and i%5==0:
			print "Hop"
		elif i%3==0:
			print "Hoppity"
		elif i%5==0:
			print "Hophop"

if __name__=="__main__":
	hop(get_input())
