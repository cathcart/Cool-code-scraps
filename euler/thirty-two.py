def comb(numbers):
	#returns a generator for all possible combinations of the numbers
	ans=[]
	if len(numbers)==1:
		yield numbers
	if len(numbers)==2:
		ans=numbers[:]
		ans.reverse()
		for i in [numbers,ans]:
			yield i
	else:
		for i in numbers:
			list=numbers[:]
			list.remove(i)
			for j in [k for k in comb(list)]:
				yield [i]+j

def combinations(iterable, r):
    # combinations('ABCD', 2) --> AB AC AD BC BD CD
    # combinations(range(4), 3) --> 012 013 023 123
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = range(r)
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)
	
#global
s=[]

def answer(a,b,r):
	#a==multiplier1, b==multiplier2, r==remainder
	global s
	list1=[int("".join([str(t) for t in x])) for x in comb(a)]
	list2=[int("".join([str(t) for t in x])) for x in comb(b)]
	list3=[int("".join([str(t) for t in a])) for a in comb(r)]
	
	for i in list1:
		for j in list2:
			if i*j in list3:
				#if [j,i] not in s:
				if i*j not in s:
					#print "%d %d %d" %(i,j,i*j)
					s.append(i*j)
					#s.append([i,j])
if __name__=="__main__":
	#this works now :)
	r=range(1,10)
	for a in combinations(r, 2):
		r1=r[:]
		for i in a:
			r1.remove(i)
		for b in combinations(r1, 3):
			r2=r1[:]
			for i in b:
				r2.remove(i)
			answer(list(a),list(b),r2)
	r=range(1,10)
	for a in combinations(r, 4):
		r1=r[:]
		for i in a:
			r1.remove(i)
		for i in r1:
			r2=r1[:]
			r2.remove(i)
			answer(list(a),[i],r2)
	#	for b in combinations(r1, 1):
#			r2=r1[:]
#			for i in b:
#				r2.remove(i)
#			answer(list(a),list(b),r2)
	print sum(s)
	#print sum([t[0]*t[-1] for t in s])

'''
result:
def pandigital(a,b):
        a=list(str(a)+str(b)+str(a*b))
        a.sort()
        if a==list("123456789"):
                return True
        return False

num=[]

for a in range(5000): #this value's are a guess
        for b in range(5000):
                if len(str(a))+len(str(b))+len(str(a*b))>9:
                        break
                elif len(str(a))+len(str(b))+len(str(a*b))!=9:
                        pass
                else:
                        if pandigital(a,b)==True and a*b not in num:
                                num.append(a*b)
print sum(num)
'''
