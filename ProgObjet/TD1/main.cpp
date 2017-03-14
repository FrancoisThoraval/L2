#include "HelloWorld.hpp"
#include "Personne.hpp"
#include "Voiture.hpp"
#include "Ensemble.hpp"
#include <iostream>


using namespace std;


void exo1(){
        HelloWorld a;

        a.sayHello();
}

void exo2(){
        Personne qqun;

        qqun.afficher();
        qqun.raz();
        qqun.afficher();
}

void exo3(){
        Voiture tuture;
        cout << "============ Afficher voiture ============" << endl;
        tuture.afficherVoiture();
        cout << "============ Ajout passager ============" << endl;
        tuture.ajoutPassager();
        cout << "============ Afficher voiture ============" << endl;
        tuture.afficherVoiture();
        cout << "============ Supprimer passager (2) ============" << endl;
        tuture.supprPassager(2);
        cout << "============ Afficher voiture ============" << endl;
        tuture.afficherVoiture();
}

void exo4(){
        Ensemble<int> ens;
        Ensemble<Personne> pers;
        Personne p("toto","tata"), p2("titi","tutu");
        ens.inserer(10);
        ens.inserer(11);
        ens.inserer(12);
        ens.inserer(13);

        pers.inserer(p);
        pers.inserer(p2);

        ens.affiche();
        cout << ens;
        cout << pers;
        ens.affiche(3);

        if(ens.appartient(12)){
          cout << "le douze est présent !" << endl;
        }

        cout << "nb elem: "<< ens.card() << endl;
        cout << "destruction par immortal joe" << endl;
}

int main() {
        // exo1(); //Faire une classe qui affiche HelloWorld
        // exo2(); //Faire une classe Personne
        // exo3(); //Classe voiture
        exo4();
        return 0;
}
