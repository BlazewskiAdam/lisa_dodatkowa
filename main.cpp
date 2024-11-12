#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// ZADANIE 1

struct wezel {
    int obwod;
    int pole;
    string nazwa;
    wezel *next;
    wezel *prev;
    wezel(int obwod, int pole, string nazwa) : obwod(obwod), pole(pole), nazwa(nazwa), next(nullptr), prev(nullptr) {}
};

class lista_dwukierunkowa {
   private:
    wezel *head;
    wezel *tail;
    unsigned rozmiar;

   public:
    // konstruktor, ustawienie wskaźników na wartośc zero
    lista_dwukierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

    // destruktor, który zwalnia pamięć, usuwając wszystkie węzły, gdy usuwamy listę
    ~lista_dwukierunkowa() {
        while (rozmiar) {
            usun_przod();
        }
    }

    void dodaj_na_poczatek(int wartosc_pola, int obwod, string nazwa) {
        wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
        new_wezel->next = head;
        head = new_wezel;
        rozmiar++;
        if (new_wezel->next) {
            new_wezel->next->prev = new_wezel;
        } else {
            tail = new_wezel;
        }
    }

    void dodaj_na_koniec(int wartosc_pola, int obwod, string nazwa) {
        wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
        new_wezel->prev = tail;
        tail = new_wezel;
        rozmiar++;
        if (new_wezel->prev) {
            new_wezel->prev->next = new_wezel;
        } else {
            head = new_wezel;
        }
    }

    void dodaj_przed_wybranym(int wartosc_pola, int obwod, string nazwa, wezel *wybrany) {
        if (wybrany == head) {
            dodaj_na_poczatek(wartosc_pola, obwod, nazwa);
        } else {
            wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
            new_wezel->next = wybrany;
            new_wezel->prev = wybrany->prev;
            rozmiar++;
            wybrany->prev->next = new_wezel;
            wybrany->prev = new_wezel;
        }
    }

    void dodaj_za_wybranym(int wartosc_pola, int obwod, string nazwa, wezel *wybrany) {
        if (wybrany == tail) {
            dodaj_na_koniec(wartosc_pola, obwod, nazwa);
        } else {
            wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
            new_wezel->next = wybrany->next;
            new_wezel->prev = wybrany;
            rozmiar++;
            wybrany->next->prev = new_wezel;
            wybrany->next = new_wezel;
        }
    }

    void usun_wybrany(wezel *wybrany) {
        rozmiar--;
        if (wybrany->prev) {
            wybrany->prev->next = wybrany->next;
        } else {
            head = wybrany->next;
        }
        if (wybrany->next) {
            wybrany->next->prev = wybrany->prev;
        } else {
            tail = wybrany->prev;
        }
        delete wybrany;
    }

    void usun_przod() {
        if (rozmiar) {
            usun_wybrany(head);
        }
    }

    void usun_tyl() {
        if (rozmiar) {
            usun_wybrany(tail);aaa
        }
    }

    void wyswietl(bool od_przodu) {
        wezel *current = od_przodu == true ? head : tail;
        while (current != nullptr) {
            cout << "Obwod: " << current->obwod << ", Nazwa: " << current->nazwa
                 << ", Pole: " << current->pole << endl;
            current = od_przodu == true ? current->next : current->prev;
        }
        cout << endl;  // Nowa linia po wyświetleniu całej listy
    }

    // TODO: Czy to na pewno dziala?
    wezel *znajdz_z_indeksu(int indeks) {
        if (indeks == 0) {
            return head;
        }
        if (indeks == rozmiar - 1) {
            return tail;
        }
        int i = 0;
        wezel *current = head;
        while (i != indeks) {
            current = current->next;
        }
        return current; // zwraca adres
    }
};

void pokazMenu() {
    cout << "====== Main Menu ======" << endl;
    cout << "1. Dodaj element na poczatek listy" << endl;
    cout << "2. Dodaj element na koniec listy" << endl;
    cout << "3. Dodaj element na wybrany indeks" << endl;
    cout << "4. Usun element z poczatku listy" << endl;
    cout << "5. Usun element z konca listy" << endl;
    cout << "6. Usun element z wybranego indeksu" << endl;
    cout << "7. Wyswietl liste" << endl;
    cout << "8. Wyswietl liste od tylu" << endl;
    cout << "9. Zakoncz program" << endl;
    cout << "Wprowadz wybor: ";
}
struct dane_figury {
    string nazwa;
    int pole;
    int obwod;
};
dane_figury figura;


int main() {
    int wybor;
    bool pokaz_menu = true;

    lista_dwukierunkowa lista;

    //TODO: dodac wywolanie funkcji z klasy i sprawdzic czy wszystko bangla
    while (pokaz_menu) {
        pokazMenu();
        cin >> wybor;
        switch (wybor) {
            case 1:
                cout << "Podaj nazwe figury: ";
            cin >> figura.nazwa;
            cout << "Podaj pole: ";
            cin >> figura.pole;
            cout << "Podaj obwod: ";
            cin >> figura.obwod;
            lista.dodaj_na_poczatek(figura.pole,figura.obwod,figura.nazwa);
                break;

            case 2:
                cout << "Podaj nazwe figury: ";
            cin >> figura.nazwa;
            cout << "Podaj pole: ";
            cin >> figura.pole;
            cout << "Podaj obwod: ";
            cin >> figura.obwod;
            lista.dodaj_na_koniec(figura.pole,figura.obwod,figura.nazwa);
                break;

            case 3:
                int indeks;
                cout << "Podaj nazwe figury: ";
            cin >> figura.nazwa;
            cout << "Podaj pole: ";
            cin >> figura.pole;
            cout << "Podaj obwod: ";
            cin >> figura.obwod;
            cout << "podaj indeks: ";
            cin >> indeks;
           //lista.dodaj_za_wybranym(figura.pole,figura.obwod,figura.nazwa,);  nie działa!!!!
                break;

            case 4:
                lista.usun_przod();
                break;

            case 5:
                lista.usun_tyl();
                break;

            case 6:
           //     lista.usun_wybrany() // rowniez nie dziala, albo jestem glupi
                break;

            case 7:
                lista.wyswietl(true);
                break;

            case 8:
                lista.wyswietl(false);
                break;

            case 9:
                cout << "Koniec programu, do zobaczenia :)" << endl;
                pokaz_menu = false;
                break;

            default:
                cout << "Bledny wybor, prosze wybrac dobra opcje." << endl;
        }

        cout << endl;
    }
    cout << lista.znajdz_z_indeksu(3);
    return 0;
}
