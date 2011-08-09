import os
import shutil,glob
def distance(input_file,a,output):
    out=open(output,"a")
    flag=False
    for line in open(input_file):
        if line.strip()=="%block AtomicCoordinatesAndAtomicSpecies":
            flag=True
        if line.strip()=="%endblock AtomicCoordinatesAndAtomicSpecies":
            flag=False
        t=line.strip().split()
        if len(t)>0 and t[-1]=="#here":
            t[2]=str(a)
            line=" ".join(t)+"\n"
	    out.write(line)
        else:
            out.write(line)

def celldm(input_file,a,output):
	        out=open(output,"a")
                for line in open(input_file):
                  l=line.split()
                  if len(l)>0 and l[0]=="celldm(1)":
                    l[2]=str(a)
                    line=" ".join(l)+"\n"
                  out.write(line)

def energy(input_file,a,output):
	        out=open(output,"a")
                for line in open(input_file):
                  l=line.split()
                  if len(l)>0 and l[0]=="ecutwfc":
                    l[2]=str(a)
                    line=" ".join(l)+"\n"
                  out.write(line)

def kpoints(input_file,a,output):
                out=open(output,"a")
                for line in open(input_file):
                  l=line.split()
                  if len(l)==6:
                    line="%s %s %s 0 0 0\n"%(str(a),str(a),str(a))
                  out.write(line)


if __name__=="__main__":
	input_file="Si.inp"
        output=input_file
        for x in range(35,75,2):
	    x=x/10.0
            x*=1.88971616463#convert from ang to bohr
	    name="%f"%(x)
            try:
                os.mkdir("dir_"+name)
                new_out="dir_"+name+"/"+output
                celldm(input_file,x,new_out)
                for pseudo in glob.glob('*.UPF'):
                    shutil.copy2(pseudo,"dir_"+name)#copy pseudopotentials across
            except:
                print "problem"
                pass
