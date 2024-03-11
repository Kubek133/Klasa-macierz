#include "macierz.h"

macierz::macierz() {
    // Konstruktor tworz¹cy macierz zerow¹.
    matrix = new double* [2];
    for (int i = 0; i < 2; ++i) {
        matrix[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

macierz::macierz(const macierz& copy) {
    // Konstruktor kopiuj¹cy.
    matrix = new double* [2];
    for (int i = 0; i < 2; ++i) {
        matrix[i] = new double[2];
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}

macierz::~macierz() {
    // Destruktor.
    for (int i = 0; i < 2; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

macierz macierz::operator * (const macierz& copy) const {
    // Operator mno¿enia macierzy.
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result.matrix[i][j] += matrix[i][k] * copy.matrix[k][j];
            }
        }
    }
    return result;
}

macierz macierz::operator + (const macierz& copy) const {
    // Operator dodawania macierzy.
    macierz result(*this);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.matrix[i][j] += copy.matrix[i][j];
        }
    }
    return result;
}

macierz macierz::operator * (const double x) const {
    // Operator mno¿enia macierzy przez skalar.
    macierz result(*this);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.matrix[i][j] *= x;
        }
    }
    return result;
}

macierz& macierz::operator =(const macierz& copy) {
    // Operator przypisania.
    if (this != &copy) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                matrix[i][j] = copy.matrix[i][j];
            }
        }
    }
    return *this;
}

bool macierz::operator == (const macierz& copy) const {
    // Operator porównania.
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (matrix[i][j] != copy.matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

macierz& macierz::operator += (const macierz& copy) {
    // Operator dodawania macierzy z przypisaniem.
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] += copy.matrix[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator *= (const macierz& copy) {
    // Operator mno¿enia macierzy z przypisaniem.
    macierz temp(*this);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                matrix[i][j] += temp.matrix[i][k] * copy.matrix[k][j];
            }
        }
    }
    return *this;
}

macierz& macierz::operator *= (const double x) {
    // Operator mno¿enia przez skalar z przypisaniem.
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] *= x;
        }
    }
    return *this;
}

void macierz::set(int i, int j, double x) {
    // Przyjmuje wartoœæ do danego elementu macierzy.
    matrix[i][j] = x;
}

double macierz::get(int i, int j) const {
    // Zwraca wartoœæ danego elementu macierzy.
    return matrix[i][j];
}

void macierz::transpozycja() {
    // Wykonuje transpozycjê macierzy.
    double temp;
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 2; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

std::ostream& operator <<(std::ostream& s, const macierz& m) {
    // Operator wyjœcia dla macierzy.
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.get(i, j) << " ";
        }
        s << std::endl;
    }
    return s;
}