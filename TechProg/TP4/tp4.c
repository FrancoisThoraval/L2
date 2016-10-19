#include <stdio.h>

#define tailleMax 50

void Inverser(int *nb1, int *nb2) {
  *nb1+=*nb2;
  *nb2=*nb1-*nb2;
  *nb1=*nb1-*nb2;
}

void AfficheTab(int tab[tailleMax],int nbE){
  printf("\n");
  for (int i = 0; i < nbE; i++) {
    printf("[%d]",tab[i]);
  }
  printf("\n");
}

void Exo2() {
  int tab[tailleMax];
  int nb,i=0,nbE=0;
  char Choix='o';
  do {
    printf("Entrez une valeur: \n");
    scanf("%d",&nb);
    tab[i]=nb;
    i++;
    nbE++;
    printf("Continuer ? (o/n) \n");
    scanf("%c*c",&Choix);

    // Debug
    AfficheTab(tab,nbE);
    printf("nbE: %d\n i: %d\n",nbE,i);
    
  } while((Choix != 'n')&&(i<tailleMax));
  AfficheTab(tab,nbE);
}

void Exo1() {
  int nb1=3;
  int nb2=6;
  int *pnb1 = &nb1;
  int *pnb2 = &nb2;
  printf("nb1: %d, nb2: %d \n", nb1,nb2);
  Inverser(pnb1,pnb2);
  printf("Inversion \n");
  printf("nb1: %d, nb2: %d \n", nb1,nb2);
}

int main() {
  // Exo1();
  Exo2();
  return 0;
}
