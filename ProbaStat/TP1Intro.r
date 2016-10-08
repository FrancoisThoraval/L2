P=function(x){
  2*x+1
}

#windows()
xli=c(0,2)
yli=c(0,4)
#curve(P(x),0,1,main="droite",lwd=5,col="purple",xlim=xli,ylim=yli) 

FuncConstante=function(x){
 1+x-x
}
FuncConstante(0)
FuncConstante(2.6)
xli=c(0,1.5)
yli=c(0,1.5)
x1=0.12
x2=0.14

xg=c(x1,x1,x2,x2,x1)
yg=c(0,1,1,0,0)

curve(FuncConstante(x),0,1,main="droite",lwd=2,col="blue",xlim=xli,ylim=yli,xaxs="i",yaxs="i")

polygon(xg,yg,col="gray85", lty=1)
