#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// ZADANIE 5

// Funkcja zamieniająca dany znak (literę) na wartość liczbową (w przypadku systemów >10)
int char_na_int(char c) {
    if (c>='0' && c<='9')
        return c-'0'; // Dla cyfr 0-9
    else if (c >= 'A' && c <= 'F')
        return c-'A'+10; // Dla liter A-F
    else if (c >= 'a' && c <= 'f')
        return c - 'a'+10; // Dla liter a-f

    return -1; // Niepoprawny znak
}

// zaimplementowanie funkcji, która przelicza liczbę na system dziesiętny
int na_dziesietny(string liczba,int system) {
    int potega = liczba.length()-1;
    int wynik=0;
    for(int i=0; i<liczba.length(); i++) {
        int całkowita = char_na_int(liczba[i]);
        wynik+= całkowita * pow(system,potega); // zastosowanie wzoru
        potega--;
    }
    return wynik;
}

// zaimplementowanie funkcji, która przelicza daną liczbę w systemie dzisiętnym na system podany przez użytkownika
string z_dziesietnego(int liczba, int system_wy) {
    string wynik = "";
    while (liczba > 0) {
        if (liczba % system_wy >= 10)  // przypadek dla systemów >10
            wynik += 'A' + (liczba % system_wy - 10); // operacje na kodach ascii, aby uzyskać litery do wyniku
        else
            wynik += to_string(liczba % system_wy); //przypadek dla cyfr 0-9
        liczba = liczba/system_wy;
    }
    reverse(wynik.begin(), wynik.end()); //użycie funkcji reverse w celu odwrócenia stringa
    return wynik;
}

bool sprawdz(string liczba, int system) {
    for (int i = 0; i<liczba.length(); i++) {
        if (liczba[i]- '0' >= system)
            return false;
    }
    return true;
}

int main() {
    string liczba;
    int system,system_wy;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    cout << "Podaj jej system: ";
    cin >> system;
    if (sprawdz(liczba,system)) {
        cout << "podaj system wyjsciowy: ";
        cin >> system_wy;
        cout << "wynik: " << z_dziesietnego(na_dziesietny(liczba,system),system_wy);
    }
    else {
        cout << "wprowadzono niepoprawne dane";
        return 0;
    }

    return 0;
}