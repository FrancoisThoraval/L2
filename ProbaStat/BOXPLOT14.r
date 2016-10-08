options(digits=6) #  pour avoir 6 chiffres significatifs - 

##########################################################
BP=function(x)  # box plot  quartiles etc  + Q3+1.5 IQD etc 
{     
med=median(x);
xs=sort(x);
#xs
n=NROW(x); n2=n%/%2; 
if (2*n2==n)   #means even n
{q1=median(xs[1:n2]); q3=median(xs[(n2+1):n]) } else
{q1=median(xs[1:(n2+1)]); q3=median(xs[(n2+1):n]) };
DIQ=q3-q1; hl=q1-1.5*DIQ; hh=q3+1.5*DIQ; 
      #whisker high   :
xh=xs[xs<=hh];
xh
wh=xh[NROW(xh)];

 #moustache  :
xl=xs[xs>=hl]; wl=xl[1];
cat("h1    moust-bas Q1     med     DIQ      Q3   moust-haut      h2", "\n" )
cat(hl ,"   ",  wl, "   ", q1 ,"   ",    med,
"   ",  DIQ,"   ",   q3,"   ",  wh,"   ",  hh, "\n" )
  }
###########################################################


