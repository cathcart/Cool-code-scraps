def one():
  #enl=range(nwf)
  enl=[]
  #nn=[1,2,2,3,3]
  nn=[1,2,2,3,3,3,4]
  #ll=[0,0,1,0,1]
  ll=[0,0,1,0,1,2,1]
  #nn={1:1,2:2,3:2,4:3,5:3}
  #zen={1:17,2:15,3:9,4:7,5:1}
  #occ={1:2,2:2,3:6,4:2,5:6}
  nwf=len(nn)
  occ=[2,2,6,2,6,0,0]
  zz=18.0

  for n in range(nwf):
    zen=0.0
    for i in range(nwf):
      if (nn[i]<nn[n]): zen+=occ[i]
      if (nn[i] == nn[n] and ll[i]<=ll[n]): zen+=occ[i]
    zen=max(zz-zen+1.0,1.0)
    print zen
    enl.append(-(zen/nn[n])**2)
  return enl

if __name__=="__main__":
  print one()
