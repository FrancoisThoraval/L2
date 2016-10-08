#include <stdio.h>

#define USD 1.19978
#define CAD 1.41748
#define CHF 1.54901
#define JYE 137.650
#define FRF 6.55957
#define MXN 13.1130

void Exo5() {
  float euros;
  float conversion;
  char change;
  printf("Tableau de changes: \n" );
  printf("USD: u  taux: %f | JYE: j taux: %f  \n",USD,JYE );
  printf("CAD: c  taux: %f | FRF: f taux: %f  \n",CAD,FRF );
  printf("CHF: h  taux: %f | MXN: m taux: %f  \n\n",CHF,MXN );

  printf("Entrez une valeur puis la lettre correspondant au change souhaité: \n" );
  do {
    printf("%s","Valeur en euros: " );
    scanf("%f%*c", &euros );
  } while(euros<0);
  printf("%s","Change: ");
  scanf("%c%*c", &change );
  switch (change) {
    case 'u': conversion = euros*USD;
      printf("conversion: %f USD \n", conversion );
      break;
    case 'c': conversion = euros*CAD;
      printf("conversion: %f CAD \n", conversion );
      break;
    case 'h': conversion = euros*CHF;
      printf("conversion: %f CHF \n", conversion );
      break;
    case 'j': conversion = euros*JYE;
      printf("conversion: %f JYE \n", conversion );
      break;
    case 'f': conversion = euros*FRF;
      printf("conversion: %f FRF \n", conversion );
      break;
    case 'm': conversion = euros*MXN;
      printf("conversion: %f MXN \n", conversion );
      break;
    default:
      printf("%s","\n//////////////////////////Mauvaise saisie ///////////////// \n\n\n" );
      Exo5();
  }
}

void Exo4() {
  int x, y, cpt, resultat;

  printf("%s","Saisie de x: " );
  scanf("%d",&x);
  printf("%s","Saisie de y: " );
  scanf("%d",&y);
  if (y==0) {
    resultat =1;
  }
  else{
    if (y==1) {
      resultat = x;
    }else{
      resultat = x;
      cpt = 0;
      while (cpt<(y-1)) {
        resultat *= x;
        cpt++;
      }
    }
  }
  printf("La valeur de %d puissance de %d est %d \n", x,y,resultat );
}

void Exo3() {
  int iDiviseur;
  int iSaisie;

  iDiviseur=1;
  printf("%s", "Entier: " );
  scanf("%d",&iSaisie);
  do {
    if ((iSaisie%iDiviseur) == 0) {
      printf("%d est un diviseur de %d \n", iDiviseur,iSaisie);
    }
    iDiviseur++;
  } while(iDiviseur<=iSaisie);
}

void Exo2() {
  int nb;

  printf("%s","Entrer un nombre: " );
  scanf("%d", &nb);
  if (nb<0) {
    for (int i = 0; i >= nb; i--) {
      printf("%d |", i );
    }
  }
  else{
    for (int i = 0; i <= nb; i++) {
      printf("%d |", i );
    }
  }
}

void Exo1() {
  int nb;
  int max;
  int min;
  int i=0;

  printf("%s\n","Entrez plusieurs valeurs, -1 pour terminer");
  do {
    scanf("%d", &nb);
    if (i == 0) {
      if (nb<0) {
        min=-1;
        max=-1;
      }
      else{
        max=nb;
        min=nb;
        i++;
      }
    }
    if (i>0) {
      if ((max<nb)&&(max!=nb)) {
        max=nb;
      }
      if ((min>nb)&&(min!=nb)&&(nb>=0)) {
        min=nb;
      }
      i++;
    }
    printf("Etape: %d // Maximum: %d Minimum: %d \n",i,max,min);

  } while(nb >= 0);
  if (nb<0) {
    printf("%s\n","Fin du programme" );
  }


}

int main() {
  // Exo1();
  // Exo2();
  // Exo3();
  // Exo4();
  Exo5();
  return 0;
}
