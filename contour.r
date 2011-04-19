#import data
#file="bc_force_surface.dat"
file="I2_bc_gga.dat"
data=read.table(file)

#assign names to the data

names(data)=c("x","y","z")
attach(data)

#reformate the data
#stride=10
stride=4
x2=x[seq(1,length(x),by=stride)]

y2=y[1:stride]
#x stride also appears here

z2=matrix(z,nrow=length(x2),ncol=length(y2),byrow=T)


pdf("I2_gga_contour.pdf")

split_point=-4196.041
point_delta=(split_point-min(z2))/10

library(lattice)

my_levels=c(seq(min(z2),split_point-point_delta,point_delta),seq(split_point,max(z2),by=(max(z2)-split_point)/3))

z2
range(z2)
my_levels

#filled.contour(x2,y2,z2,col=topo.colors(27),
#key.title=title(main="Total\nenergy\n(eV)"),
#xlab=expression(paste("b parameter (",ring(A),")")),
#ylab=expression(paste("c parameter (",ring(A),")")),
#plot.axis={axis(1);axis(2);
#contour(x2,y2,z2,labcex=1.5,nlevels=27,add=T)})
filled.contour(x2,y2,z2,col=topo.colors(13),
cex.lab=1.5,
key.title=title(main="Total\nenergy\n(eV)"),
xlab=expression(paste("b parameter (",ring(A),")")),
ylab=expression(paste("c parameter (",ring(A),")")),
levels=my_levels,
plot.axis={axis(1);axis(2);
contour(x2,y2,z2,labcex=1.5,levels=my_levels,add=T)})

#filled.contour(x2,y2,z2,
##col=topo.colors(14),
##col=heat.colors(14),
##levels=c(seq(0,split_point-point_delta,point_delta)),
##col=heat.colors(25),
##xlim = c(4.0,max(x2)),
##ylim = c(8.0,11.0),
#key.title=title(main="Total\nenergy\n(meV)"),
#xlab=expression(paste("b parameter (",ring(A),")")),
#ylab=expression(paste("c parameter (",ring(A),")")))


pdf("I2_gga_surface.pdf")

zlim=c(0,max(z2)) # limits in z coordinates 
theta=30         # see option theta in persp
phi=30          # see option phi in persp

nrz <- nrow(z2) 
ncz <- ncol(z2) 
ncol=14          # the number of colors to use 

couleurs  <- tail(topo.colors(trunc(140 * ncol)),ncol) 
fcol      <- couleurs[trunc(z2/zlim[2]*(ncol-1))+1] 
dim(fcol) <- c(nrz,ncz) 
fcol      <- fcol[-nrz,-ncz]

persp(z2,col=fcol)#,zlim=zlim,theta=theta,phi=phi,zlab="density") 

#require(MASS)
#kde2dplot<-function(z2,ncol=50,nlevels=20,theta=30,phi=30)
#my_colours<-tail(topo.colors(1.4*ncol(z2)),ncol(z2))
#fcol<-my_colours[trunc(z2*(ncol(z2)-1))+1]
#dim(fcol)<-c(nrow(z2),ncol(z2))
#fcol
#fcol<-my_colours[trunc(z2)+1]
#wireframe(z2,drape=T,col.region=fcol)
#
#
#range(z2)
#library(grDevices)
#custom_colours<-colorRampPalette(c("red","orange","blue"),space="rgb",bias=100)
#wireframe(z2,row.values=x2,column.values=y2,aspect=c(1,0.75),
#drape=T,colorkey=T,
#screen = list(z = 30+180, x = -80,y=-10),
#scales = list( arrows=FALSE, z = list(tick.number=5),x=list(tick.number=5),y=list(tick.number=5)),
##scales = list(z.ticks=2, arrows=T),
##col.regions=topo.colors(71),
#col.regions=custom_colours(71),
#zlab="Total\nenergy\n(meV)",
##par.box = list(col=NA,col=NA),
##col.regions=b[1:71],
##col.regions=heat.colors(71),
##col.regions=heat.colors(4),
##xlim = c(4.0,max(x2)),
##ylim = c(8.0,max(y2)),
#xlab=expression(paste("b parameter (",ring(A),")")),
#ylab=expression(paste("c parameter (",ring(A),")")))
