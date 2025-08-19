#include <iostream>
#include <string>
using namespace std;

// Funkcje, które będą przechowywane w tablicy
int pole_kwadratu(int a, int b) {
    return a * a;
}

int pole_trojkata(int a, int h) {
    return a * h / 2;
}

int pole_prostokata(int a, int b) {
    return a * b;
}

int pole_rombu(int a, int h) {
    return a * h;
}

// Struktura przechowująca nazwę funkcji i wskaźnik do niej
struct Wprowadzenie_funkcji {
    string* name;           // wskaźnik na tekst
    int (*funkcja)(int, int); // wskaźnik na funkcję
};

// Wprowadzenie tablicy obiektów utworzonych na podstawie struktury "Wprowadzenie_funkcji"
Wprowadzenie_funkcji funkcje[] = {
    {new string("pole_kwadratu"), pole_kwadratu},
    {new string("pole_trojkata"), pole_trojkata},
    {new string("pole_prostokata"), pole_prostokata},
    {new string("pole_rombu"), pole_rombu}
};

int main() {
    string nazwa_funkcji;
    int arg1, arg2;
    cout << "Wprowadz nazwe funkcji: ";
    cin >> nazwa_funkcji;
    cout << "Wprowadz dwa argumenty: ";
    cin >> arg1 >> arg2;

    bool znaleziono = false;

    // Szukamy funkcji po jej nazwie za pomocą pętli
    for (int i = 0; i < 4; i++) {
        if (nazwa_funkcji == *funkcje[i].name) {  // Porównanie za pomocą dereferencji wskaźnika
            cout << "Wynik: " << funkcje[i].funkcja(arg1, arg2) << endl;
            znaleziono = true;
            break;
        }
    }

    if (!znaleziono)
        cout << "Blad: nie znaleziono funkcji o nazwie '" << nazwa_funkcji << endl;

    // Zwalnianie pamięci
    for (int i = 0; i < 4; i++)
        delete funkcje[i].name;


    return 0;
}
