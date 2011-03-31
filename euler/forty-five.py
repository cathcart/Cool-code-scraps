N=60000
t=set([n*(n+1)/2 for n in range(1,N)])
p=set([n*(3*n-1)/2 for n in range(1,N)])
h=set([n*(2*n-1) for n in range(1,N)])

print (t&p)&h
