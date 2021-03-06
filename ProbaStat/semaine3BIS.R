#setwd("@workingDirectory")     D�finit le r�pertoire de travail
#install.packages("Ecdat")      Pour installer un package
#library(Ecdat)                 Ouvrir la biblioth�que

#Computers[1:10,]               Afficher les 10 premiers �l�ments

rm(list=ls())
library(Ecdat)
Computers[1:10,]

c= Computers

c[2,8] #2eme ligne, 8eme colonne
c[2,]  #Affiche toute la 2eme ligne

c$price[1:10] #Affiche que la colonne price

summary(c) #Donne un r�sum� pour chaque colonne

summary(c$speed) #Donne un r�sum� de la colonne speed

pr20 = c$price[1:20] #On r�cup�re les 20 premiers prix
pr20

prord20 = sort(pr20) #On ordonne les 20 premiers prix et on les mets dans prord20
prord20

mediane = (prord20[10]+prord20[11])/2

q1 = (prord20[5]+prord20[6])/2
q3 = (prord20[15]+prord20[16])/2

DIQ= q3-q1 #Distance inter-quartile
h1= q1 -1.5*DIQ 
h2= q3 +1.5*DIQ

mediane
q1
q3
DIQ 
h1
h2

source("BOXPLOT14.r") #fonction R pour diagramme moustache

BP(prord20)

mean(prord20) #Moyenne

So= sum(prord20) #Somme
S2= sum(prord20^2) #Somme des carr�s

So 
S2

n = length(prord20)
VarEmp = S2/(n-1) - So^2/(n*(n-1)) #Ou S2/(n-1) - So^2/(n-1)/n Il faut essayer de limiter les parenth�ses
VarEmp

EcartTypeEmp = sqrt(VarEmp)
EcartTypeEmp

sd(prord20) #EcartTypeEmp

#windows()

bv=boxplot(prord20,col="red") #cr�ation du diagramme � moustache de prord20
bv

summary(c$price) #R�sum� de tout les prix

windows()
li = c(0,7000)
par(mfrow=c(2,1)) # graphes sur 2 lignes, 1 colonne
boxplot(c$price,horizontal = TRUE,col = "red", ylim =li,main="Diagramme oklm")
hist(c$price,col="blue",xlim=li,main="Aight lourde moustache") #freq = F --> met en notation scientifique

# Commentaire:
#
# La distribution des prix est asym�trique 
# avec beaucoup de valeurs au del� de la 
# moustache sup�rieure - (<=> comparaison moyenne/m�diane)
#                                           2235 /  2144
