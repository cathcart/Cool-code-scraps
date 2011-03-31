def triplet(m,n):
	return [(m**2-n**2),(2*m*n),(m**2+n**2)]

def no_solutions(p):
	N=30
        s=[]
        for m in range(2,N):
                for n in range(1,m):
                        t=sorted(triplet(m,n))
                        if t[-1]>t[0]+t[1] and sum(t)==p and t not in s:
                                s.append(t)
                        elif p%sum(t)==0:
                                k=sorted([p/sum(t)*x for x in t])
                                if k not in s:
                           	     s.append(k)
        return len(s)


def ans():
	max_sol=[0,0]
	for p in range(1,1001):
		no=no_solutions(p)
		if no>max_sol[0]:	
			max_sol=[no,p]
	print max_sol

if __name__=="__main__":
	ans()
