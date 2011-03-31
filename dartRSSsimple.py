import feedparser
import time

feed = feedparser.parse('http://www.irishrail.ie/realtime/publicinfo.asp?strLocation=PERSE')

print feed.feed.title

targets = ['Bray', 'Greystones']

# initialise current time
now = time.localtime()

# now find the right darts
for entry in feed.entries:
    dart = entry.title
    dart_ = dart.split()
    # destination is last word in each item
    if dart_[-1] in targets:
        # get the hours and minutes of the dart arrival, convert to minutes
        hours_eta, mins_eta = dart_[0].split(':')
        delta_min = 60*int(hours_eta) + int(mins_eta)

        # do the same with the current time
        now_min = 60*int(now[3]) + int(now[4])

        eta = int(delta_min - now_min)   
        print("[ arriving in %3d minutes ]  %s" % (eta, dart))     
