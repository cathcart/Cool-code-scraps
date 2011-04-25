#run with R -f final.r
#load the necessary libraries
library(lattice)

#import data
#file="bc_force_surface.dat"
file="I2_bc_force.dat"
#file="I2_bc_gga.dat"
#file="I2_bc_vdw.dat"
#file="tmp"
data=read.table(file)

#assign names to the data
names(data)=c("x","y","z")
attach(data)

#reformate the data
stride=10#force
#stride=4#gga,vdw
x2=x[seq(1,length(x),by=stride)]

y2=y[1:stride]
#x stride also appears here

#create the z matrix
z2=matrix(z,nrow=length(x2),ncol=length(y2),byrow=T)

#setup my nonlinear levels
#split_point=-4200#gga
#split_point=-4250#vdw
split_point=0.05#force
lower_number=10
upper_number=3

point_delta=(split_point-min(z2))/lower_number
my_levels=c(seq(min(z2),split_point-point_delta,point_delta),seq(split_point,max(z2),by=(max(z2)-split_point)/upper_number))

#create the contour plot
pdf("I2_force_contour.pdf")

filled.contour(x2,y2,z2,col=topo.colors(length(my_levels)),
cex.lab=1.5,
key.title=title(main="Total\nenergy\n(eV)"),
xlab=expression(paste("b parameter (",ring(A),")")),
ylab=expression(paste("c parameter (",ring(A),")")),
levels=my_levels,
plot.axis={axis(1);axis(2);
contour(x2,y2,z2,labcex=1.5,levels=my_levels,add=T)})

#create surface plot
pdf("I2_force_surface.pdf")

wireframe(z2,drape=T,
#cex.lab=1.5,
row.values=x2,column.values=y2,aspect=c(1,0.75),
at=my_levels,col.regions=topo.colors(length(my_levels)),
scales = list( arrows=FALSE,cex=1.2, z = list(distance=1.2,tick.number=3),x=list(tick.number=3,distance=1.2),y=list(distance=1.2,tick.number=3)),
xlab=list(expression(paste("b parameter (",ring(A),")")),cex=1.4),
ylab=list(expression(paste("c parameter (",ring(A),")")),cex=1.4,space="bottom"),
#zlab=list("Total energy (eV)",cex=1.2,rot=90),#gga,vdw
zlab=list("Total force",cex=1.2,rot=90),#force
#title(main="main title", sub="sub-title"),
#zlab=list("Total\nenergy\n(meV)",cex=1.4),
colorkey=list(labels=list(main="something",cex.lab=1.5)),
screen = list(z = 30+180, x = -80,y=-10))
