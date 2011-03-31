from numpy import *
from math import log, cos

def lor(E):
    delta=0.1
    return delta/(pi*(delta*delta+E*E))
#D=0
#for i in arange(-100,100,0.01):
    #D+=lor(i)
#print D

def simpson(f, a, b, n):
    "Approximate the definite integral of f from a to b by Simpson's rule."

    if n % 2 != 0:
        print "Ups: n must be even!"
        return -1
        
    h  = (float(b) - a)/n
    
    si = 0.0
    sp = 0.0
    
    for i in range(1, n, 2):
        xk = a + i*h
        si += f(xk)
    
    for i in range(2, n, 2):
        xk = a + i*h
        sp += f(xk)
        
        
    s = 2*sp + 4*si + f(a) + f(b)

    return (h/3)*s
print simpson(lor, -10, 10, 400000)
