#include <iostream>

int main(int argc, char const *argv[]) {
  int *tab;

    tab = new int[9];
    tab[0] = 1;
    tab[1] = 3;
    for (int i = 0; i < 10; i++) {
      tab[i] = i;
    }
    for (int i = 0; i < 10; i++) {
      std::cout << "tab[i]: " << tab[i]<< '\n';
    }

  return 0;
}
