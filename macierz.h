#ifndef MACIERZ
#define MACIERZ

#include <iostream>

/// Klasa reprezentuj�ca macierz 2x2.
class macierz {
public:
    /// Konstruktor domy�lny tworz�cy macierz zerow�.
    macierz();

    /// Konstruktor kopiuj�cy.
    macierz(const macierz& copy);

    /// Destruktor.
    ~macierz();

    /// Operator mno�enia macierzy.
    macierz operator * (const macierz& copy) const;

    /// Operator dodawania macierzy.
    macierz operator + (const macierz& copy) const;

    /// Operator mno�enia macierzy przez skalar.
    macierz operator * (const double x) const;

    /// Operator przypisania.
    macierz& operator =(const macierz& copy);

    /// Operator por�wnania.
    bool operator == (const macierz& copy) const;

    /// Operator dodawania macierzy z przypisaniem.
    macierz& operator += (const macierz& copy);

    /// Operator mno�enia macierzy z przypisaniem.
    macierz& operator *= (const macierz& copy);

    /// Operator mno�enia przez skalar z przypisaniem.
    macierz& operator *= (const double x);

    /// Przyjmuje warto�� do danego elementu macierzy.
    void set(int i, int j, double x);

    /// Zwraca warto�� danego elementu macierzy.
    double get(int i, int j) const;

    /// Wykonuje transpozycj� macierzy.
    void transpozycja();

private:
    double** matrix;
};
/// Operator wyj�cia dla macierzy.
std::ostream& operator <<(std::ostream& s, const macierz& m);

#endif // MACIERZ
