import math
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

def f(t):
    if abs(t)<0.5:
        return 1
    else:
        return 0

def g(x):
    if (x)<0:
        return 0
    else:
        return math.exp(-x)


def c(t,tau):
    #return f(tau)*g(t-tau)
    #return math.sin(tau)*math.cos(t-tau)
    return g(tau)*g(t-tau)

if __name__=="__main__":
    N=10

#    values=[g(float(x)/10)*0.1 for x in range(10)]
#    print sum(values)
#    print simpson(g,-4,4,200)

    for t in range(100):
        t=float(t)/10
        def d(x):
            return c(t,x)
        print t,simpson(d,-N,N,10000)

