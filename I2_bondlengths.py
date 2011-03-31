import math
def inter_atomic(b,c):
    #u=0.15
    #v=0.117
    u=0.17689845
    v=0.12381319
    return 2*math.sqrt(u*u*b*b+v*v*c*c)

def inter_molecular(b,c):
    #u=0.15
    #v=0.117
    u=0.17689845
    v=0.12381319
    return [0.5*math.sqrt(b*b+(1-4*v)*(1-4*v)*c*c),0.5*math.sqrt(c*c+(1-4*u)*(1-4*u)*b*b)]

if __name__=="__main__":
    b=2*2.263275
    c=9.78

    #b=4.686
    #c=9.784

    print inter_atomic(b,c)
    print inter_molecular(b,c)

