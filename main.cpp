#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

// ZADANIE 1

//pojedyńczy element listy (węzeł)
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
    //dodawanie elementu na poczatek listy
    void dodaj_na_poczatek(int wartosc_pola, int obwod, string nazwa) {
        wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
        new_wezel->next = head;
        head = new_wezel;
        rozmiar++;
        if (new_wezel->next) {
            new_wezel->next->prev = new_wezel;
        } else { // przypadek, gdy lista jest pusta
            tail = new_wezel;
        }
    }

    //dodawanie elementu na koneic listy
    void dodaj_na_koniec(int wartosc_pola, int obwod, string nazwa) {
        wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa);
        new_wezel->prev = tail;
        tail = new_wezel;
        rozmiar++;
        if (new_wezel->prev) {
            new_wezel->prev->next = new_wezel;
        } else { //przypadek, gdy lista jest pusta
            head = new_wezel;
        }
    }

    void dodaj_przed_wybranym(int wartosc_pola, int obwod, string nazwa, wezel *wybrany) {
        if (wybrany == head) {
            dodaj_na_poczatek(wartosc_pola, obwod, nazwa);
        } else {
            wezel *new_wezel = new wezel(obwod, wartosc_pola, nazwa); //dynamiczne zaalokowanie nowego węzła
            new_wezel->next = wybrany;
            new_wezel->prev = wybrany->prev;
            rozmiar++;
            wybrany->prev->next = new_wezel;
            wybrany->prev = new_wezel;
        }
    }

    //usuwanie wybranego elementu
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

    //usuwanie pierwszego elementu listy
    void usun_przod() {
        if (rozmiar) {
            usun_wybrany(head);
        }
    }

    //usuwanie ostatniego elementu listy;
    void usun_tyl() {
        if (rozmiar) {
            usun_wybrany(tail);
        }
    }

    //wyświetlanie listy w zależności od wartości bool
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
            i++;
            current = current->next;
        }
        return current;
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

int main() {
    int wybor;
    bool pokaz_menu = true;
    dane_figury figura;
    lista_dwukierunkowa lista;
    wezel* w;
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
                w=lista.znajdz_z_indeksu(indeks);
                lista.dodaj_przed_wybranym(figura.pole,figura.obwod,figura.nazwa,w);
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

    return 0;
}
