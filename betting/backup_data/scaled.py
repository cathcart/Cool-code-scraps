import sys
import string
import re
input_file=sys.argv[1]

infile=open(input_file)

for line in infile:
    items=line.split()
    if items[0] != "Group":
        name=items[0][2:]
        num_start=1
        if str.isalpha(items[1]):
            name=name+"-"+items[1]
            num_start+=1
        name=string.lower(name)
        print name,
        for i in [num_start,num_start+4,num_start+5,num_start+6]:#print no._matches,GF,GA,pts
            print items[i].rstrip('-'),
        print
