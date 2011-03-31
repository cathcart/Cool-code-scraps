def final(n):
	s=0
	list=[]
	c=[0,0,0,0,0,0,0,0]
	for a in range(n/200+1):
		c[0]=a
		r=n-a*200
		for b in range(r/100+1):
			c[1]=b
			r1=r-b*100
			for c_p in range(r1/50+1):
				c[2]=c_p
				r2=r1-c_p*50
				for d in range(r2/20+1):
					c[3]=d
					r3=r2-d*20
					for e in range(r3/10+1):
						c[4]=e
						r4=r3-e*10
						for f in range(r4/5+1):
							c[5]=f
							r5=r4-f*5
							for g in range(r5/2+1):
								c[6]=g
								c[7]=r5-g*2
								s+=1
								#print c
	return s
#print [200,100,50,20,10,5,2,1]
print final(200)
