import poss
import string
from match_result import match_result
A=["mexico","uruguay","south-africa","france"]#maybe some correction
B=["argentina","nigeria","greece","south-korea"]
C=["england","usa","algeria","slovenia"]
D=["germany","australia","serbia","ghana"]
E=["netherlands","denmark","japan","cameroon",]
F=["italy","paraguay","new-zealand","slovakia"]
G=["ivory-coast","portugal","brazil","north-korea"]
H=["honduras","chile","spain","switzerland"]

def scores(match_results,teams,pts,wdl):
        if match_results[0]>match_results[1]:
                pts[teams[0]]+=3
                wdl[teams[0]][0]+=1
                wdl[teams[1]][2]+=1
        elif match_results[1]>match_results[0]:
                pts[teams[1]]+=3
                wdl[teams[1]][0]+=1
                wdl[teams[0]][2]+=1
        elif match_results[0]==match_results[1]:
                pts[teams[0]]+=1
                pts[teams[1]]+=1
                wdl[teams[0]][1]+=1
                wdl[teams[1]][1]+=1




#generate dictionary for results
#first generate a tuple

def group(a):
    wdl_tuple=[]
    pts_tuple=[]
    for i in a:
            wdl_tuple.append([i,[0,0,0]])
            pts_tuple.append([i,0])
    
    #convert tuple to dictionary
    pts=dict(pts_tuple)
    wdl=dict(wdl_tuple)
    
    
    #now generate fixtures and calculate results

    for i in range(len(a)):
            for j in range(len(a)):
                    if j>i:
                            tmp=match_result([a[i],a[j]])
                            scores(tmp,[a[i],a[j]],pts,wdl)
                            print a[i]," v ",a[j],"  ",tmp
    return [sorted(pts, key=pts.get),wdl]
    #print sortedDictValues(results)
    #print results
def elimination():
    t=0
    round1=[]
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    for i in [A,B,C,D,E,F,G,H]:
        [results,wdl]=group(i)
        name="Group"+string.upper(alpha[t])
        print name
        print results
        round1.append([name,[results[-1],results[-2]]])
        t+=1
        #for i in results:
            #print i,
        #print
        #for i in results:
            #print wdl[i],
        #print
    round1_dic=dict(round1)
    #print type(round1_dic)
    #print round1_dic['GroupA']
    return round1_dic
