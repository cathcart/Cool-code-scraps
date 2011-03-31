import string
import feedparser
d=feedparser.parse('http://www.irishrail.ie/realtime/publicinfo.asp?strLocation=PERSE')

title=d.feed.title
print title
i=title.split()
time=i[-1][:-2].split(":")

def list_search(item,list):
	truth=0
	for i in list:
		if i==item:
			truth=1
	return truth

wanted=["Bray","Greystones"]

for i in d.entries[:]:
	line=i.title
	items=line.split()
	line_status=0
	for k in items:
		if list_search(k,wanted):
			line_status=1
	if line_status:
		print line,
		dart_time=items[0].split(":")
		hours=int(dart_time[0])-int(time[0])
		mins=int(dart_time[1])-int(time[1])
		if hours==0:
			print "\t%d mins"%mins
		else:
			print "\t%d mins"%(60*hours + mins)

