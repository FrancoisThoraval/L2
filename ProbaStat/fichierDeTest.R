c= Computers
windows()
li = c(0,7000)
par(mfrow=c(2,1)) # graphes sur 2 lignes, 1 colonne
boxplot(c$price,horizontal = TRUE,col = "red", ylim =li,main="Diagramme oklm")
hist(c$price,col="blue",xlim=li,main="Aight lourde moustache") #freq = F --> met en notation scientifique
