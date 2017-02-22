#include <iostream>
#include <cstring>

using namespace std;

void exo2(){
  char strNom[50] = "Thoraval", strPrenom[50] = "François";
  char chaineConcatenee[50];

  // strPrenom = "François";
  // strNom = "Thoraval";

  strcpy(chaineConcatenee, strNom);
  strcat(chaineConcatenee, strPrenom);

  cout << strNom << endl;
  cout << strPrenom << endl;
  cout << chaineConcatenee << endl;

  cout << strNom + strPrenom << endl;
}

int main() {

  exo2();

  return 0;
}
