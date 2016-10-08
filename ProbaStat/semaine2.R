vector= c(-2,4,0.5,2,1,5,0.6,0.2,1,3) #vecteur

p0 = function(x){
  res = ifelse(x<1 & x>0 ,1,0)
  res
}

xli=c(-1,2)
yli=c(0,1.5)
windows()
curve(p0(x),-1,2,main="droite",lwd=3,n=10000,col="green",
      xlim=xli,ylim=yli,xaxs="i",yaxs="i")

x1 = 0.25
x2 = 0.5

xg=c(x1,x1,x2,x2,x1)
yg=c(0,1,1,0,0)

polygon(xg,yg,
        col="red", 
        lty = c("dashed", "solid"),
        density = c(10, 20))


n = 100
xv = runif(n) #random uniform
xv

xv[2]
xv[2:6]

xv1 = xv[xv<0.25]
xv1

xv2 = xv[xv>0.25 & xv<0.5]
xv2

xv3 = xv[xv>0.5 & xv<0.75]
xv3

xv4 = xv[xv>0.75 & xv<1]
xv4

fr2 = length(xv2) #nbr d'elements de xv2

frequenceRelXv2= fr2/n
frequenceRelXv2

fr1 = length(xv1)
frequenceRelXv1 = fr1/n
frequenceRelXv1

fr3 = length(xv3)
frequenceRelXv3 = fr3/n
frequenceRelXv3

fr4 = length(xv4)
frequenceRelXv4 = fr4/n
frequenceRelXv4

#somme des frequ rel = 1

frequenceRelXv1 + frequenceRelXv2 + frequenceRelXv3 + frequenceRelXv4

#Somme des longueurs/frequence (frx) = n

vecFreq = c(frequenceRelXv1,frequenceRelXv2,frequenceRelXv3,frequenceRelXv4)

s1 = seq(0,1, by=0.25)
h1 = hist(xv,breaks = s1,freq=FALSE,col="grey",xaxt="n")
axis(1, at = seq(0,1, by =0.25))

points(c(0,1), c(1,1), type="l", lwd=3, col="blue")

#en augmentant n on se rapproche de 1
#les frequences relatives tendent/convergent vers les probabilités 
