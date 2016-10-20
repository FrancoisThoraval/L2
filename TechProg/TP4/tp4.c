#include <stdio.h>
#include <stdlib.h>

#define tailleMax 1

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

// Permet de vider le buffer
void clean_stdin(void)
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void TriBulle(int *tab, int nbE){
  int desordre = 0;
  int *ptr=&tab[0];
  // printf("ptr: %d ptr+1: %d",*ptr,*(ptr+1));
  while (desordre==0) {
    desordre =1;
    for (int i = 0; i < nbE; i++) {
      if (*(ptr+i)>*(ptr+i+1)) {
        Inverser((ptr+i),(ptr+i+1));
        desordre=0;
      }
    }
  }
}

void Saisie() {

}

void Exo2() {
  int taille;
  int *tab=NULL;
  int nb,i=0,nbE=0;

  printf("Combien d'elements souhaité: \n");
  scanf("%d",&taille);
  tab=malloc(taille * sizeof(int));

  if (tab==NULL) {
    printf("Erreur lors de l'allocation mémoire du tableau\n");
  }
  for (i = 0; i < taille; i++) {
    printf("valeur n°%d: \n",i+1);
    scanf("%d*c",&nb);
    clean_stdin(); //On vide le buffer apres chaque saisie sinon ca boucle deux fois ...
    tab[i]=nb;
    nbE++;
  }
  AfficheTab(tab,nbE);
  TriBulle(tab,nbE);
  AfficheTab(tab,nbE);
  free(tab);
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
