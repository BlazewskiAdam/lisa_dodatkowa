#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// ZADANIE 1

//pojedyĹ„czy element listy (wÄ™zeĹ‚)
    struct wezel {
        int obwod;
        int pole;
        string nazwa;
        wezel *next;
        wezel *prev;
        //konstruktor, ktĂłry inicjalizuje obiekt struktury wÄ™zeĹ‚
        //ustawia rĂłwnieĹĽ potrzebne wartoĹ›ci na podstawie danych argumentĂłw oraz 2 wskaĹşniki na wartoĹ›c zero.
        wezel(int obwod, int pole, string nazwa) : obwod(obwod), pole(pole), nazwa(nazwa), next(nullptr), prev(nullptr) {}
};

class lista_dwukierunkowa {
   private:
    wezel *head;
    wezel *tail;
    unsigned rozmiar;

   public:
    // konstruktor, ustawienie wskaĹşnikĂłw i rozmiaru listy na wartoĹ›c zero
    lista_dwukierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

    // destruktor, ktĂłry zwalnia pamiÄ™Ä‡, usuwajÄ…c wszystkie wÄ™zĹ‚y, gdy usuwamy listÄ™
    ~lista_dwukierunkowa() {
        while (rozmiar) {
            usun_przod();
        }
    }
    //dodawanie elementu na poczatek listy
    void dodaj_na_poczatek(int pole, int obwod, string nazwa) {
        wezel *nowy_wezel = new wezel(obwod, pole, nazwa); //dynamiczne zaalokowanie nowego wÄ™zĹ‚a
        nowy_wezel->next = head; //ustawienie wskaĹşnika next noewgo wÄ™zĹ‚a na head
        head = nowy_wezel; //aktualizacja head na nowy wÄ™zeĹ‚
        rozmiar++;
        if (nowy_wezel->next) {
            nowy_wezel->next->prev = nowy_wezel; //ustawienie wskaĹşnika prev poprzedniego wÄ™zĹ‚a na nowy
        } else { // przypadek, gdy lista jest pusta
            tail = nowy_wezel;
        }
    }

    //dodawanie elementu na koneic listy
    void dodaj_na_koniec(int pole, int obwod, string nazwa) {
        wezel *nowy_wezel = new wezel(obwod, pole, nazwa); //dynamiczne zaalokowanie nowego wÄ™zĹ‚a
        nowy_wezel->prev = tail; //ustawienie wskaĹşnika prev nowego wÄ™zĹ‚a na tail
        tail = nowy_wezel;// aktualizacja tail na nowy wÄ™zeĹ‚
        rozmiar++;
        if (nowy_wezel->prev) {
            nowy_wezel->prev->next = nowy_wezel; //ustawienie wskaĹşnika next poprzedniego wÄ™zĹ‚a na nowy
        } else { //przypadek, gdy lista jest pusta
            head = nowy_wezel;
        }
    }

    void dodaj_na_wybrany(int pole, int obwod, string nazwa, wezel *wybrany) {
        if (wybrany == head) {
            dodaj_na_poczatek(pole, obwod, nazwa);
        }
        else if (wybrany == tail) {
            dodaj_na_koniec(pole, obwod, nazwa);
        }
        else {
            wezel *nowy_wezel = new wezel(obwod, pole, nazwa); // dynamiczne zaalokowanie nowego wÄ™zĹ‚a
            nowy_wezel->next = wybrany;
            nowy_wezel->prev = wybrany->prev; //ustawienie wskaĹşnika prev nowego wÄ™zĹ‚a na wartoĹ›Ä‡ prev i-tego wÄ™zĹ‚a
            wybrany->prev->next = nowy_wezel; // Ustawienie wskaĹşnika next poprzednika i-tego wÄ™zĹ‚a (wybrany->prev) na nowy wÄ™zeĹ‚.
            wybrany->prev = nowy_wezel;
            // po danych instrukcjach "wypychamy" o 1 dalej dany element oraz wstawiamy nowy na jego miejsce
            rozmiar++;
        }
    }


    //usuwanie wybranego elementu
    void usun_wybrany(wezel *wybrany) {
        rozmiar--;
        if (wybrany->prev) {
            wybrany->prev->next = wybrany->next; //ustawienie wskaĹşnika next poprzednika "wybrany" na "wybrany -> next"
        } else {
            head = wybrany->next;
        }
        if (wybrany->next) {
            wybrany->next->prev = wybrany->prev; //ustawienie wskaĹşnika prev nastÄ™pnika "wybrany" na "wybrany -> prev"
        } else {
            tail = wybrany->prev;
        }
         delete wybrany; //usuwamy dany wÄ™zeĹ‚
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

    //wyĹ›wietlanie listy w zaleĹĽnoĹ›ci od wartoĹ›ci bool
    void wyswietl(bool od_przodu) {
        wezel *current;
        if (od_przodu)
            current = head;
        else
            current = tail;
        while (current != nullptr) { // przejĹ›cie przez kaĹĽdy element listy
            cout << "Nazwa: " << current->nazwa << ", Pole: " << current->pole << ", Obwod: " << current->obwod << endl; //wyĹ›wietlanie danych wÄ™zĹ‚Ăłw listy za pomocÄ… wskaĹşnikĂłw
            if (od_przodu)
                current = current->next;
            else
                current = current->prev;
        }
    }

    //znajdowanie wskaĹşnika w liĹ›cie o podanym indeksie
    wezel *znajdz_z_indeksu(int indeks) {
        if (indeks == 0) {
            return head;
        }
        if (indeks == rozmiar - 1) {
            return tail;
        }
        int i = 0;
        wezel *current = head; //zadeklarowanie wskaĹşnika pomocniczego
        while (i != indeks) {
            i++;
            current = current->next; //szukanie wskaĹşnika o podanym indeksie po caĹ‚ej liĹ›cie
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
                cout << w;
                lista.dodaj_na_wybrany(figura.pole,figura.obwod,figura.nazwa,w);
                break;

            case 4:
                lista.usun_przod();
                break;

            case 5:
                lista.usun_tyl();
                break;

            case 6:
                int indeks_1;
                cout << "podaj indeks: ";
                cin >> indeks_1;
                w = lista.znajdz_z_indeksu(indeks_1);
                lista.usun_wybrany(w);
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
