#include <iostream>
#include "Produit.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
        Produit p;
        Produit p1;

        p.setNom("Babar");
        p.setId(120);
        cout << p << endl;

        p1 = p;
        cout << p1 << endl;
        return 0;
}
