#import data
file="bc_force_surface.dat"
data=read.table(file)

#assign names to the data

names(data)=c("x","y","z")
attach(data)

#reformate the data
x2=x[seq(1,length(x),by=10)]
#10 is the stride of the x coord

y2=y[1:10]
#x stride also appears here

z2=matrix(z,nrow=length(x2),ncol=length(y2),byrow=T)


pdf("contour_test.pdf")

library(lattice)
filled.contour(x2,y2,z2,
levels=c(seq(0,0.045,0.045/10),seq(0.05,max(z2),by=(max(z2)-0.05)/3)),
key.title=title(main="Total\nenergy\n(meV)"),
xlab=expression(paste("b parameter (",ring(A),")")),
ylab=expression(paste("c parameter (",ring(A),")")))


pdf("surface_test.pdf")

wireframe(z2,aspect=c(1,0.75),drape=T,colorkey=F,
screen = list(z = 30+180, x = -80,y=-10),
#key.title=title(main="Total\nenergy\n(meV)"),
zlab="Total\nenergy\n(meV)",
xlab=expression(paste("b parameter (",ring(A),")")),
ylab=expression(paste("c parameter (",ring(A),")")))
