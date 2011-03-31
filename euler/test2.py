def pandig(i,j):
    n = i*j
    s = str(i) + str(j) + str(n)
    digSet = set(s)
    if '0' in s:
        return False
    if len(digSet)==9 and len(s)==9:
        return True
    else:
        return False
 
 
prods=set()
for i in range(0,100):
    for j in range(i,10000):
        if (pandig(i,j)):
            n=i*j
            prods.add(n)
            print i,j,n
 
print prods
print sum(list(prods))
