import string
attack_file=open("final_data")
rank_file=open("attack.dat")

def read_in(file_in):
    dic=dict()
    for line in file_in:
        items=line.split()
        dic[string.lower(items[0])]=[float(items[1]),float(items[2])]
    return dic

def double_sort(dic,k):
    e=dic.keys()
    if k==0:
        e.sort(lambda a,b: -1*cmp(dic[a][0],dic[b][0]))
    if k==1:
        e.sort(lambda a,b: -1*cmp(dic[a][1],dic[b][1]))
    return e

rank_dic=read_in(rank_file)
sorted_rank_dic=double_sort(rank_dic,1)

sorted_rank_rank=dict()
i=0
for x in sorted_rank_dic:
    i+=1
    #print x," ",rank_dic[x]
    sorted_rank_rank[x]=i
    
attack_dic=read_in(attack_file)
sorted_attack_dic=double_sort(attack_dic,0)
sorted_attack_rank=dict()
i=0
for x in sorted_attack_dic:
    i+=1
    sorted_attack_rank[x]=i
    #print x," ",attack_dic[x]
    
#for x in sorted_rank_rank:
    #try:
        #print x," ",sorted_rank_rank[x]-sorted_attack_rank[x]
    #except:
        #pass
    

def dic_value_find(dic,val):
    for x in dic:
        if dic[x]==val:
            return x

for x in rank_dic:
    #teams pts rank
    pts_rank=sorted_rank_rank[x]
    #equil ranked team from attack index
    equil_team=dic_value_find(sorted_attack_rank,pts_rank)
    #get equil team attack score
    equil_attack=attack_dic[equil_team]
    #a=(sorted_rank_rank[x]-sorted_attack_rank[x])%10*0.25
    test=(sorted_rank_rank[x]-sorted_attack_rank[x])
    if test<0:#teams attack rank is lower than expected 
        a=0.70
    elif test>0:#teams attack rank is higher than expected
        a=0.30
    b=1-a
    print x," ",a*equil_attack[0]+b*attack_dic[x][0]," ",a*equil_attack[1]+b*attack_dic[x][0]




    #print x," ",
    #try:
        #print sorted_attack_dic[dic_value_find(sorted_attack_rank,sorted_rank_rank[x])]
    #except:
        #print

#def attack_rank_shuffle():
    #for x in sorted_rank_rank:
        #test=sorted_rank_rank[x]-sorted_attack_rank[x]
        #if test>0 and test>tolerance:
            ##float down
            #t=sorted_attack_rank[x]+1#find this value to get name of new
            #sorted_attack_dic[x]=
            #pass
        #if test<0 and abs(test)>tolerance:
            ##float up
            #pass