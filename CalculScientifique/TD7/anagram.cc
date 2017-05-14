#include <algorithm>
#include <iostream>
#include "vecteur.h"
#include <fstream>
#include <map>

using namespace  std;
Vecteur<int> ens_positions;// ensemble des positions vecteur de 0 à nbre delettres du mot-1

Vecteur<Vecteur<int> > lettre_positions; // pour chaque lettres formant le mot, les positions de celles si dans l'anagramme. C'est ce vecteur qui correspond à la partition de ens_positions

Vecteur<int>  lettres;// vecteur des lettres distinctes formant le mot

Vecteur<int> compteur;// vecteur des du nombre d'occurence de chaque lettre dans le mot

int nlettrestotal; // nombre total de lettres

// La construction des anagrammes revient à partitionner l'ensemble des positions
// possibles (données par la longueur du mot), en un p sous ensembles ou p est le
//nombre de lettres distinctes formant le mot.
// Le cardinal de chaque sous-ensemble est égal au nombre de fois où la letter associée
// apparait dans le mot.
/*----------------------------------------------------------*/
void lettresCompteur(Vecteur<int> & motnum)
{
  // **** A écrire !!
  // le mot à anagrammer (numérisé) est passé en argument. Il s'agit ici de
  // remplir le vecteur des lettres (distinctes)
  // qui compose le mot.
  // De plus, il faudra construire le vecteur "compteur" qui donne pour chacune
  // de ces lettres, le nombre de fois où celle-ci appararait dans le mot.
    int tab[26];
    int k=0;
    for(int i=0;i<26;i++){
      tab[i]=i;
    }

    for(double i=0;i<motnum.size();i++){
      k=0;
      if(tab[motnum[i]] ==-1){

      } else {
        for(double j=0;j<motnum.size();j++){
          if(motnum[j]==motnum[i]){
            k++;
          }
        }
        compteur.push_back(k);
        lettres.push_back(motnum[i]);
        tab[motnum[i]]=-1;
      }
    }
    // std::cout <<std::endl<< "motnum" << std::endl;
    // for(int i =0;i<motnum.size();i++){
    //   std::cout<<motnum[i]<<" ";
    // }
    // std::cout <<std::endl<< "tab" << std::endl;
    // for(int i =0;i<26;i++){
    //   std::cout<<tab[i];
    // }
    //
    //
    // std::cout<<std::endl<< "Lettre : "<<std::endl;
    // for(int i=0;i<lettres.size();i++){
    //   std::cout<<lettres[i]<<" ";
    // }
    // std::cout<<std::endl<< "compteur :"<<std::endl;
    // for(int i=0;i<compteur.size();i++){
    //   std::cout<<compteur[i];
    // }

}

int factorielle(int n)
{
  return (n == 1 || n == 0) ? 1 : factorielle(n - 1) * n;
}

 float  calculNAnagram(Vecteur<int> motnum)
{
   float rescomp = 1;
  for(double i = 0;i<compteur.size();i++){
    rescomp *= factorielle(compteur[i]);
  }
  // std::cout << rescomp << std::endl;
  return(factorielle(motnum.size())/rescomp);
}

/*----------------------------------------------------------*/
void numerise(const string& text,Vecteur<int>& textnum )
{
  // fonction à utiliser. Ne pas modifier
  // numérisation d'un text en vecteur d'entier
  textnum.reInit(text.length());
  for (double i=0; i<text.length(); i++)
  {
    textnum[i]=int(text[i])-int('a');
  }
}
/*----------------------------------------------------------*/
void textise(string& text)
{
  // fonction à utiliser. Ne pas modifier
  // fonction à utiliser pour afficher les anagrammes obtenues.
  // std::cout << endl<<"LETTRE " << std::endl;
  // for(double i =0;i<lettre_positions.size();i++){
  //   for(double j = 0;j<lettre_positions[i].size();j++){
  //     cout<<lettre_positions[i][j]<<" ";
  //   }
  // }
  // std::cout << "/* message0 */" << std::endl;
  Vecteur<int> textnum(nlettrestotal);
  for (double i=0; i<lettre_positions.size(); i++)
  {

    for (double j=0; j<lettre_positions[i].size(); j++)
    {

      textnum[lettre_positions[i][j]]=lettres[i];

    }
  }
  for (double i=0; i<textnum.size(); i++)
  {
    // std::cout << "/* message1 */" << std::endl;
    text.push_back(char(textnum[i]+int('a')));
    // cout<<text<<endl;
  }
}
/*---------------------------------------------------------*/
void positionRestantes(Vecteur<int>& newpos)
{
  // fonction à utiliser. Ne pas modifier
  // cette fonction met à jour les positions encore disponibles
  newpos.reInit(ens_positions.size());
  newpos=ens_positions;
  for (double ilettre=0; ilettre<lettre_positions.size();ilettre++)
  {
    for (double ipos=0; ipos<lettre_positions[ilettre].size();ipos++)
    {
      if (lettre_positions[ilettre][ipos]!=-1)
      {
        for( double i = newpos.size()-1; i >= 0; i-- ) if( newpos[i]==lettre_positions[ilettre][ipos] ) newpos.erase( newpos.begin()+i );
      }
    }
  }

}
/*---------------------------------------------------------*/
void reInitPosition(int indlettre)
{
  // fonction à utiliser. Ne pas modifier
  // cette fonction réinitialise la partition à partir d'une certaine lettre
  for (double i=indlettre;i<lettre_positions.size();i++ )
  {
    for (double ipos=0;ipos<lettre_positions[i].size();ipos++ )
    {
      lettre_positions[i][ipos]=-1;
    }

  }
}
/*---------------------------------------------------------*/

void positionneLettres(int& count,int ideb, int k, int indlettre,  std::vector<int> posrestantes)
{

  // fonction récursive de production des anagrammes
  // Elle est basée sur des combinaisons successives de manière à produire toutes partitions d'un ensemble
  // de positions.

  // indlettre est l'indice de la lettre traitée. Il s'agit de produire les combinaisons de p positions
  // parmi les positions disponibles restantes, où p est le nombre d'occurence de la lettre.

  //posrestantes: vecteur des positions disponibles.
  // count: compteur d'anagramme pour vérif.
  // std::cout << endl<< "K = " <<k<< std::endl;

  if (k==0)
  {
    // une combinaison est terminé. Un lettre est complètement positionnée
    // std::cout <<endl<< "Indlettre : "<<indlettre << std::endl;
    if (indlettre==lettres.size()-1)
    {
      // on a traité toutes les lettres. On a donc une nouvelle anagramme.
      // il faut l'afficher en utilisant la fonction textise
      //**** compléter
      std::string letstring;
     //  std::cout << endl<<"test3" << std::endl;
      textise(letstring);
     //  std::cout << "=============================================================================================================================" << std::endl;

      std::cerr<<++count<<"-->"<<letstring<<'\n';
      return;
    }
    // on passe à la lettre suivante
    indlettre++;
    // il faut mettre à jour les positions disponibles.
    Vecteur<int> nlles_posrestantes;
    // std::cout << endl<<"test4" << std::endl;
    // les partitions sont remises à jour à partir de la lettre en cours.
    reInitPosition(indlettre+1);
    positionRestantes(nlles_posrestantes);
    // std::cout << endl<< "NOUVELLE POS RESTANTE" << std::endl;
    // for(double i =0;i<nlles_posrestantes.size();i++){
    //   cout<<nlles_posrestantes[i];
    // }
   //**** appel récursif pour traiter la lettre suivante
   positionneLettres(count,ideb+1,compteur[indlettre],indlettre,nlles_posrestantes);
    return;
  }
  int n=posrestantes.size();
  for (int i=0; i<n-k+1;i++)
  {
    //**** deux lignes ici pour la récursivité
    // std::cout << endl<<"test2" << std::endl;
    // for(double a = 0;a<posrestantes.size();a++){
    //   cout<<posrestantes[a];
    // }
    // cout<<endl;
    Vecteur<int> subpos(posrestantes);
    // std::cout << "SUBPOS" << std::endl;
    // for(double i =0;i<subpos.size();i++){
    //   cout<<subpos[i];
    // }

    // reInitPosition(indlettre);
    // positionRestantes(subpos);
    subpos.erase(subpos.begin());
    reInitPosition(indlettre);
    // std::cout << endl << "SUBPOS 2!" << std::endl;
    // for(double i =0;i<subpos.size();i++){
    //      cout<<subpos[i];
    // }
    // getchar();

    for(int i = 0;i<lettre_positions[indlettre].size();i++){
          lettre_positions[indlettre][i] = compteur[indlettre];
     }
    std::cout << '\n';
    positionneLettres(count,ideb+1,k-1,indlettre,subpos);
    // subpos.erase(subpos.begin()+1);
  }

}
/*---------------------------------------------------------*/
void anagram()
{

  lettre_positions.reInit(compteur.size());
  // initialisation de la partition. Toutes les positions prennent -1
  for (double i=0; i<compteur.size(); i++)
  {
    lettre_positions[i].reInit(compteur[i],-1);
  }
  int count=0;
  /**** demarrage de la récursivité;*/
  // std::cout <<endl<< "test1" << std::endl;
  // std::cout << "ens_positions" << std::endl;
  // for(double a = 0;a<ens_positions.size();a++){
  //   cout<<ens_positions[a];
  // }
  positionneLettres(count,0,compteur[0],0,ens_positions);
}



// -----------------------------------------------------------
void anagrammeFacile(string mot) {
     int i = 1;
     sort(mot.begin(), mot.end());
     cout << i << "-->" << mot << endl;
     while(next_permutation(mot.begin(), mot.end()))
          cout << ++i << "-->" << mot << endl;
}

/*---------------------------------------------------------*/
int main()
{
  std::string mot="mississippi";
  Vecteur<int> motnum;
  numerise(mot,motnum);
  //**** initialiser l'ensemble des positions
  // std::cout << mot.size() << std::endl;
  for(double i=0;i<mot.size();i++){
    ens_positions.push_back(i);
  }
  lettresCompteur(motnum);
  //  std::cout<<calculNAnagram(motnum)<<endl;
  nlettrestotal=motnum.size();
  // anagram();
  //**** afficher le nombre d'anagrammes

  /*****************************************************************/
  // Solution alternative pour obtenir tout les anagrammes souhaités
  anagrammeFacile(mot);
}
