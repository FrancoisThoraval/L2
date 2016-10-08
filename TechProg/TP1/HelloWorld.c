// gcc -o NomExec source.c --> génère fichier executable
// gcc -c source.c --> génère fichier objet source.c
// gcc -o ... -DDEBUG ... --> génère programme qui inclue les partie DDEBUG
// gcc -S --> génère le code assemebleur

#include <stdio.h>

#define Passable 10
#define ABien 12
#define Bien 14
#define TBien 16


// Afficher si un étufiant est reçu à un examen suivant sa note (switch)
// passable = [10,12]
// Assez Bien = [12,14]
// Bien = [14,16]
// Très Bien [16,20]
// Evolution: On peut mettre en constante le texte qui s'affiche en fonction des cas

void Exo4(){
    int note;
    printf("Entrez la note: " );
    scanf("%d",&note );
    switch (note) {
        case Passable-10:
        case Passable-9:
        case Passable-8:
        case Passable-7:
        case Passable-6:
        case Passable-5:
        case Passable-4:
        case Passable-3:
        case Passable-2:
        case Passable-1: printf("%s\n","Etudiant non reçu" );
            break;
        case Passable:
        case ABien-1:printf("%s\n","Etudiant reçu avec mention Passable" );
            break;
        case ABien:
        case Bien-1:printf("%s\n","Etudiant reçu avec mention Assez bien" );
            break;
        case Bien:
        case TBien-1: printf("%s\n","Etudiant reçu avec mention Bien" );
            break;
        case TBien:
        case TBien+1:
        case TBien+2:
        case TBien+3:
        case TBien+4: printf("%s\n","Etudiant reçu avec mention Très bien" );
        break;
        default: Exo4();
    }
}

// Saisir une lettre ou un numéro et dire si c'est un chiffre, une majuscule ou une minuscule
void Exo3b() {
    char Lettre;
    int valeurASCII;
    printf("%s","Entrez une lettre: " );
    scanf("%c",&Lettre);
    valeurASCII=Lettre;
    if ((valeurASCII>=48) && (valeurASCII <=57)) {
        printf("%s\n","C'est un chiffre !" );
    }
    else if ((valeurASCII>=97) && (valeurASCII <=122)) {
            printf("%s\n","C'est une minuscule" );
        }
        else if ((valeurASCII>=65) && (valeurASCII <=90)) {
            printf("%s\n","C'est une majuscule" );
        }
            else
                printf("%s\n","C'est un caractère spécial" );
}

// Saisir un nombre, vérifier qu'il est 0<x<20
// Modifier prog afin de vérifier une série de nombre
// Calculer moyenne de ces nombres

void Exo3(){
    int nb1;
    int sum =0;
    float res;
    int n =0;
    do {
        printf("%s%d","Entrez 7 nombres entiers (",n);
        printf("%s","): " );
        scanf("%d",&nb1 );
        if ((nb1<=20)&&(nb1>=0)) {
            sum=sum+nb1;
            n++;
        }
        else
        printf("%s\n","Erreur, nbr >= 20 ou <= 0 !" );

    } while(n<8 );
    res = (float)sum/n;
    printf("%s%f\n","Moyenne = ", res );
}

// Entrer deux nombres, faire le produit (tester avec des short (%hd), long (%ld), reel (%f), entier (%d)) (char %c)
// nbr d'octets codant short == 2 octets -> 2⁶ valeurs possibles
// nbr d'octets codant int == 2 à 4 octets -> 2⁶ à 2³² valeurs possibles
// nbr d'octets codant long == 4 octets -> 2³² valeurs possibles
void Exo2(){
    float nb1;
    float nb2;

    printf("%s\n","Entrez deux nombres entiers: " );
    printf("%s","nb1: " );
    scanf("%f",&nb1);
    printf("%s","nb2: " );
    scanf("%f",&nb2 );
    printf("%s%f \n","Le produit de ces deux nombres est: ",nb1*nb2);
}

//Afficher Hello World!
void Exo1(){
    printf("%s\n","Hello World!" ); //%s string
}

int main() {
    int Choix;

    printf("%s\n"," ================= MENU =================" );
    printf("%s\n"," 1) Exo1" );
    printf("%s\n"," 2) Exo2" );
    printf("%s\n"," 3) Exo3a" );
    printf("%s\n"," 4) Exo3b" );
    printf("%s\n"," 5) Exo4" );
    printf("%s\n"," 9) Quitter" );
    printf("%s\n"," ========================================" );
    printf("%s\n\n","Choix: " );
    scanf("%s", Choix );

    switch (Choix) {
      case 1: Exo1();
        break;
      case 2: Exo2();
        break;
      case 3: Exo3();
        break;
      case 4: Exo3b();
        break;
      case 5: Exo4();
        break;
      case 9: printf("%s\n","Adieu l'ami !" );
        break;
    }

    return 0;
}
