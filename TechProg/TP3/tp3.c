#include <stdio.h>

#define tailleMax 50

typedef struct{
  char niveau; //'m' en montée, 'c' niveau constant, 'd' en descente
  float inclinaison;
}Profil;

typedef struct{
  char State; //'n' nominal, 'a' alerte, 'd' detresse
}Etat;

typedef struct {
  char code[tailleMax];
  float altitude;
  float cap;
  Profil profile;
  float autonomy;
  Etat state;
}Avion;

Avion Creer(){
  Avion plane;
  printf("Code: ");
  scanf("%s*c",plane.code );
  printf("Altitude: ");
  scanf("%f*c",plane.altitude);
  printf("Cap: ");
  scanf("%f*c", plane.cap);
  printf("Profil ('m' montée, 'c' constant, 'd' descente): ");
  scanf("%c*c", plane.profile.niveau);
  printf("Profil (inclinaison): ");
  scanf("%f*c", plane.profile.inclinaison);
  printf("Autonomie");
  scanf("%f*c",plane.autonomy);
  printf("Etat: ('n' nominal, 'a' alerte, 'd' detresse)");
  scanf("%c",plane.Etat.State);

  return plane;
}

void Afficher(Avion plane) {

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
    case 1: plane=Creer();
      break;
    case 2: Afficher(plane);
      break;
    default:
      break;
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
  // Exo1();
  Exo2();
  return 0;
}
