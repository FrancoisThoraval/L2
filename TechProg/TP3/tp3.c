#include <stdio.h>

#define tailleMax 10

typedef struct{
  char niveau; //'m' en montée, 'c' niveau constant, 'd' en descente
  float inclinaison;
}Profil;

typedef struct {
  char code[tailleMax];
  float altitude;
  float cap;
  Profil profile;
  float autonomy;
  char state; //'n' nominal, 'a' alerte, 'd' detresse
}Avion;

int *Saisie(int tab[]){
  int nb, nbE=0;
  int i;

  printf("Entrez 5 valeurs dans le tableau: \n" );
  for (i = 0; i < 5; i++) {
    printf("valeur n° %d: ", i );
    scanf("%d", &nb);
    tab[i]=nb;
    nbE++;
  }

  tab[i+1]=nbE;
  return tab;
}

void Affiche(int tab[], int nbE) {
  for (int i = 0; i < nbE; i++) {
    printf("[%d]", tab[i]);
  }
}

void AfficherElem(int tab[]) {
  int n, i=0;
  printf("Saisir n: ");
  scanf("%d", &n);
  n--;
  for (i=0; i < n; i++) {
  }
  printf("[%d]", tab[i]);
}

int RechercherElem(int tab[],int nbE){
  int elem, *pElem, i=0;

  printf("Element recherché ?: ");
  scanf("%d",&elem);

  pElem = &tab[0];
  while ((*pElem != elem) && (i<nbE)) {
    *pElem++;
    i++;
  }
  printf("Element trouvé en position: %d\n",i);
  return *pElem+1;
}

void Trier(int tab[],int nbE){
  int i,j,save,pos;

  // Tri par insertion
  for (i = 0; i < nbE; i++) {
    pos=i;
    for (j = i+1; j < nbE ; j++) {
      if (tab[j]<tab[i]) {
        pos=j;
      }
    }
    save = tab[i];
    tab[i]=tab[pos];
    tab[pos]=save;
  }
  Affiche(tab,nbE);
}

void Exo7(int tab[],int nbE) {
  int Choix;

  printf("\n\n===========MENU===========\n\n");
  printf("1) Saisir nouveau tableau\n");
  printf("2) Afficher le tableau\n");
  printf("3) Afficher element i\n");
  printf("4) Rechercher Element\n");
  printf("5) Trier le tableau\n");
  printf("==========================\n\n");
  printf("Choix: ");
  scanf("%d",&Choix);

  switch (Choix) {
    case 1: Saisie(tab);
            Exo7(tab,nbE);
      break;
    case 2: Affiche(tab,nbE);
            Exo7(tab,nbE);
      break;
    case 3: AfficherElem(tab);
            Exo7(tab,nbE);
      break;
    case 4: RechercherElem(tab,nbE);
            Exo7(tab,nbE);
      break;
    case 5: Trier(tab,nbE);
            Exo7(tab,nbE);
      break;
  }
}

// Exo 6 ----------------------------------
//              #     #   #   #    #      #
//              #  A  # B # C # P1 #  P2  #
// ########################################
// Init         #  1    2   3   /     /
// P1=&A        #  1    2   3   &A    /
// P2=&C        #                     &C
// *P1=(*P2)++  #  4
// P1 = P2      #  2
// P2=&B        #                     &B
// *P1-=*P2     #  0
// ++*P2        #       3
// *P1*=*P2     #  0
// A=++*P2**P1  #  0
// P1=&A        #                &A
// *P2=*P1/=*P2 #  0    0
//

void AfficheExo5(int tab[], int etape) {
  printf("\n étape n° %d:\n", etape);
  for (int i = 0; i < tailleMax; i++) {
    printf("[%d]", tab[i]);
  }
}

void Exo5(){
  int T1[tailleMax], T2[tailleMax]={0,-2,2,9,-5,4,6,-7,4,5};
  int j=0,i;
  AfficheExo5(T2,1);

  for (i = 0; i < tailleMax; i++) {
    if (T2[i]>=0){
      T1[j]=T2[i];
      j++;
    }
  }
  while (j<i) {
    T1[j+1]=0;
    j++;
  }
  AfficheExo5(T1,3);

}

void Exo4() {
  int i;
  int *pi = &i;

  printf("Entrez une valeur (i): ");
  scanf("%d", &i);
  printf("i: %d, pi: %d \n\n",i,*pi);
  printf("Entrez une valeur (pi): ");
  scanf("%d", &*pi);
  printf("i: %d, pi: %d \n\n",i,*pi);
}

Avion Creer(){
  Avion plane;
  printf("Code: ");
  scanf("%s*c",plane.code);
  printf("Altitude: ");
  scanf("%f*c",&plane.altitude);
  printf("Cap: ");
  scanf("%f*c", &plane.cap);
  printf("Profil ('m' montée, 'c' constant, 'd' descente): ");
  scanf("%s*c", &plane.profile.niveau);
  printf("Profil (inclinaison): ");
  scanf("%f*c", &plane.profile.inclinaison);
  printf("Autonomie: ");
  scanf("%f*c", &plane.autonomy);
  printf("Etat ('n' nominal, 'a' alerte, 'd' detresse): ");
  scanf("%s", &plane.state);

  return plane;
}

void Afficher(Avion plane) {
  printf("===================================================\n");
  printf("Code: %s \n", plane.code);
  printf("Altitude: %f \n", plane.altitude);
  printf("Cap: %f \n", plane.cap);
  switch (plane.profile.niveau) {
    case 'm': printf("Profil: Montée \n");
      break;
    case 'c': printf("Profil: Constant \n");
      break;
    case 'd': printf("Profil: Descente \n");
      break;
    default: printf("Profil: Impossible de récuperer la donnée\n inclinaison: %f \n", plane.profile.inclinaison);
  }
  printf("Autonomie: %f \n", plane.autonomy);
  switch (plane.state) {
    case 'n': printf("Nominal \n");
      break;
    case 'a': printf("Alerte \n");
      break;
    case 'd': printf("Detresse \n");
      break;
  }
}

void Exo3() {
  int choix;
  Avion plane;

  printf("=================== MENU =================== \n\n");
  printf("1) Creer un nouvel avion \n");
  printf("2) Afficher avion \n\n");
  printf("Choix: " );
  scanf("%d", &choix);
  printf("============================================ \n\n");
  switch (choix) {
    case 1:  plane=Creer();
             Afficher(plane);
      break;
    case 2:  Afficher(plane);
      break;
    default: Exo3();
  }
}

void Exo2() {
  int tab[tailleMax];
  int nb, nbE=0;

  printf("Entrez 5 valeurs dans le tableau: \n" );
  for (int i = 0; i < tailleMax; i++) {
    printf("valeur n° %d : ", i );
    scanf("%d", &nb);
    #ifdef DEBUG
      printf("i est supérieur à 3" );
    #endif
    tab[i]=nb;
    nbE++;
  }
}

void Exo1() {
  int numerateur , denominateur , resultat=0, reste ,m;
  printf ("entrez les valeurs: " );
  scanf( "%d∗c ",&numerateur );
  scanf ("%d∗c ",&denominateur );
  if (numerateur>denominateur){
    reste = numerateur;
    m = denominateur;
  }
  else {
    reste = denominateur;
    m = numerateur;
  }
  while (reste >= m){
     resultat++;
     reste -= m;
   }
  printf("Resultat %d %d %d %d" , numerateur , denominateur , resultat , reste);
}

int main() {
  int tab[tailleMax];
  int nbE=0;
  // Exo1();
  // Exo2();
  // Exo3();
  // Exo4();
  // Exo5();
  // Exo6 en commentaires
  Exo7(tab,nbE);
  return 0;
}
