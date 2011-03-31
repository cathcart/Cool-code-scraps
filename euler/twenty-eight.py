def spiral(N):
	diagonal=[1]
	for i in range(3,N+1):
		if i%2!=0:
			for k in range(4):
				diagonal.append(i**2-k*(i-1))
	return sum(diagonal)

def short(N):
	return 1+sum([i**2-k*(i-1) for k in range(4) for i in range(3,N+1) if i%2!=0])

print short(1001)
