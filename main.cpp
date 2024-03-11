#include <iostream>
#include "macierz.h"

int main() {
    macierz A;
    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    macierz B;
    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    std::cout << "Macierz A:\n" << A << std::endl;
    std::cout << "Macierz B:\n" << B << std::endl;

    macierz C = A * B; // Mno¿enie macierzy
    std::cout << "Macierz C = A * B:\n" << C << std::endl;

    macierz D = A + B; // Dodawanie macierzy
    std::cout << "Macierz D = A + B:\n" << D << std::endl;

    return 0;
}
