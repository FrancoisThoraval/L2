#include <iostream>

int main(int argc, char *argv[])
{

//    QApplication app(argc,argv);
  const int ni = 10;
  const int nc = 10;
  int ** tableau;
  tableau = new int* [ni];
  for ( int i=0; i < ni; i++)
          tableau[i] = new int [nc];

  tableau[5][6]=5;

    for ( int i=0 ; i < ni ; i++){
      for ( int j=0 ; j < nc ; j++){
        std::cout << tableau[i][j];
      }
      std::cout << '\n';
    }

  for ( int i=0 ; i < ni ; i++)
    delete tableau [i];
  delete tableau;

    return 0;
}
