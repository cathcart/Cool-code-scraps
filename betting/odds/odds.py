odds_file=open("odds.dat")
data_file=open("tmp")

odds=[]
for i in odds_file:
	items=i.split()
	odds.append([items[0],float(items[1])])
data=[]
for i in data_file:
        items=i.split()
        data.append([items[0],[float(items[1]),float(items[2])]])
ODDS=dict(odds)
DATA=dict(data)

for i in DATA:
	try:
		t=1/float(ODDS[i])
		print i," ",DATA[i][0]," ",DATA[i][1]," ",t
	except:
		print i," ",DATA[i][0]," ",DATA[i][1]
