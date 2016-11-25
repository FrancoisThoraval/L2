#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 50
// int const NMAX = 50;

typedef char mot[NMAX];

void majuscules(char *dest, char *src){
  int asciiChar;
  for (int i = 0; i <  strlen(src); i++) {
    asciiChar = (int) src[i];
    printf("asciiChar: %d\n",asciiChar);
    asciiChar -= 32;
    dest[i] = asciiChar;
  }
}

void mirroir(char *dest, char *src){
  int length = strlen(src)-1;
  for (int i = 0; i < length; i++) {
    dest[i] = src[length-i-1];
  }
}

void afficher(char *chaine){
  for (int i = 0; i < strlen(chaine); i++) {
    printf("%c",chaine[i]);
  }
  printf("\n");
}

void Exo1(){
  mot src;
  mot dest;
  char *psrc = &src[0];
  char *pdest = &dest[0];
  printf("Entrez une chaine: ");
  fgets(src,NMAX,stdin);
  afficher(psrc);
  mirroir(pdest,psrc);
  afficher(pdest);
  majuscules(pdest,psrc);
  afficher(pdest);
}

int main() {
  Exo1();
  return 0;
}
