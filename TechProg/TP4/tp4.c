#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define tailleMax 1
#define tailleMaxChar 50

void Inverser(int *nb1, int *nb2) {
  *nb1+=*nb2;
  *nb2=*nb1-*nb2;
  *nb1=*nb1-*nb2;
}

void AfficheTab(int tab[tailleMax],int nbE){
  printf("\n");
  for (int i = 1; i <= nbE; i++) {
    printf("[%d]",tab[i]);
  }
  printf("\n");
}

// Permet de vider le buffer
void clean_stdin(void){
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
    for (int i = 1; i <= nbE; i++) {
      if (*(ptr+i)>*(ptr+i+1)) {
        Inverser((ptr+i),(ptr+i+1));
        desordre=0;
      }
    }
  }
}

int *Saisie(int *tab,int nbE) {
  int taille;
  int nb,i=0;

  printf("Combien d'elements souhaité: \n");
  scanf("%d",&taille);
  tab=malloc(taille * sizeof(int));

  if (tab==NULL) {
    printf("Erreur lors de l'allocation mémoire du tableau\n");
  }
  for (i = 1; i < taille+1; i++) {
    printf("valeur n°%d: \n",i);
    scanf("%d*c",&nb);
    clean_stdin(); //On vide le buffer apres chaque saisie sinon ca boucle deux fois ...
    tab[i]=nb;
    tab[0]= ++nbE;
  }
  return tab;
}

int longueur_chaine1(char tabC1[tailleMax]){
  int length =0;
  length = strlen(tabC1);
  return length;
}

int longueur_chaine2(char *C2){
  int length =0;
  length=strlen(C2);
  return length;
}

char *saisir(char *chaine){
  printf("Entrez la chaine: \n");
  fgets(chaine,tailleMaxChar,stdin);

  return chaine;
}

void afficher(char *chaine){
  printf("\n");
  for (int i = 0; i < strlen(chaine); i++) {
    printf("%c",chaine[i]);
  }
  printf("\n");
}

char *inverser(char *chaine){
  char save;
  int length = strlen(chaine);
  for (int i = 0; i < length/2; i++) {
    save = chaine[length-i-1];
    chaine[length-i-1] = chaine[i];
    chaine[i]=save;
  }
  return chaine;
}

void compte(char *chaine) {
  char separator = ' ';
  int nbMot =1;
  for (int i = 0; i < strlen(chaine); i++) {
    if (chaine[i] == separator) {
      nbMot++;
    }
  }
  printf("nombre de mots: %d\n",nbMot);
}

void Exo4(){
  int Choix;
  char tabC[tailleMaxChar];
  char *chaine=&tabC[0];
  do{
    printf("=================== MENU ===================\n");
    printf("  1) Saisir\n");
    printf("  2) Afficher\n");
    printf("  3) Inverser\n");
    printf("  4) Compte\n");
    printf("============================================\n");

    printf("Choix: \n");
    scanf("%d",&Choix);
    switch (Choix) {
      case 1: chaine = saisir(chaine);
        break;
      case 2: afficher(chaine);
        break;
      case 3: chaine = inverser(chaine);
        break;
      case 4: compte(chaine);
        break;
      default: exit(0);
    }
  }while ((Choix == 1)||(Choix == 2 )||(Choix == 3 )||(Choix == 4 ));
}

void Exo3(){
  int longC1;
  int longC2;
  char tabC1[tailleMaxChar]={'a','z','e','r','t','y'};
  char tabC2[tailleMaxChar]={'q','w','e','r','t','y'};
  char *C2 = &tabC2[0];
  longC1 = longueur_chaine1(tabC1);
  longC2 = longueur_chaine2(C2);
  printf("longC1: %d// longC2: %d \n",longC1,longC2 );
}

void Exo2() {
  int *tab=NULL;
  int nbE=0;

  tab = Saisie(tab, nbE);
  nbE= tab[0];
  printf("*tab: %d",tab[0]);

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
  // Exo2();
  // Exo3();
  Exo4();
  return 0;
}
