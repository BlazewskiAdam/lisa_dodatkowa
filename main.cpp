#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

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
    void wyswietl() {
        wezel* current = head;
        while (current != nullptr) {
            cout << "Obwod: " << current->obwod << ", Nazwa: " << current->nazwa << ", Pole: " << current->pole << endl;
            current = current->next;
        }
        cout << endl; // Nowa linia po wyświetleniu całej listy
    }


};
int main(){

    lista_dwukierunkowa prostokat;
    prostokat.dodaj(23,14,"prostokat");
    prostokat.dodaj(23,25,"trojkat");
    prostokat.wyswietl();
    return 0;
}
