#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// ZADANIE 5
int na_dziesietny(int liczba,int system) { // zaimplementowanie funkcji, która przelicza liczbe o dowolnym systemie na liczbę o systemie dziesiętnym.
    int potega=0;
    int wynik=0;
    while (liczba>0) {
        wynik+=liczba%10*pow(system,potega);
        potega++;
        liczba/=10;
    }
    return wynik;
}
string z_dziesietnego(int liczba,int system_wy){ // zaimplementowanie funkcji, która przelicza daną liczbę w systemie dzisiętnym na inną liczbę o podanym systemie przez użytkownika, (system wy).

    string wynik="";
    while (liczba>0) {
        wynik+=to_string(liczba%system_wy); // zamiana wyniku obliczeń na stringa, aby dodać liczbę jako kolejną cyfrę danej liczby.
        liczba/=system_wy;

    }
    reverse(wynik.begin(),wynik.end()); // użycie funkcji reverse z biblioteki alghoritm, w celu odwrócenia kolejności cyfr.
    return wynik;
}
// ZADANIE 1

struct wezel {
    int obwod;
    string nazwa;
    int pole;
    wezel* next;
    wezel* prev;
    wezel(int obwod,string nazwa, int pole) : obwod(obwod), next(nullptr), prev(nullptr),pole(pole),nazwa(nazwa)  {}

};
class lista_dwukierunkowa {
private:
    wezel* head;
    wezel* tail;
public:
    lista_dwukierunkowa() : head(nullptr), tail(nullptr) {} // konstruktor listy, ustawienie wskaźników na wartośc zero
    ~lista_dwukierunkowa() { // zaimplementowanie destruktora, który zwalnia pamięć, usuwając wszystkię węzły, gdy kończymy implementować listę.
        wezel* current = head;
        while (current != nullptr) {
            wezel* next = current->next;
            delete current;
            current = next;
        }
    }
    void dodaj(int wartosc_pola,int obwod, string nazwa) {
        wezel* new_wezel = new wezel(obwod,nazwa,wartosc_pola);
        if (head == nullptr) { // instrukcja, w przypadku pustej listy
            head = new_wezel;
            tail = new_wezel;
        }
        else { // instrukcja, w przypadku, gdy lista nie jest pusta
            tail->next = new_wezel;
            new_wezel->prev = tail;
            tail = new_wezel;
        }
    }
    // void wyswietl() {
    //     wezel* current = head;
    //     while (current != nullptr) {
    //         cout << current-> << endl;
    //         current = current->next;
    //     }
    // }
};
int main(){
    // int liczba;
    // int system;
    // int system_wy;
    // cout << "Podaj liczbe: ";
    // cin >> liczba;
    // cout << "Podaj system: ";
    // cin >> system;
    // cout << endl;
    // cout << "podaj system wyjściowy";
    // cin >> system_wy;
    // cout << z_dziesietnego(na_dziesietny(liczba,system),system_wy); // wywołanie 2 funkcji, które wykonują nasze zadanie.
    lista_dwukierunkowa prostokat;
    return 0;
}
