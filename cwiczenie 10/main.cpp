//Wiktor St�pniewski
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>

// wesja bez wskaznika

using namespace std;
const int N = 10;

struct Pisarz
{
    int rok_urodzenia;
    char nazwisko[20];
};
struct Ksiazka
{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz autor;
};

void getPisarz(Pisarz nazwa);
void getKsiazka(Ksiazka nazwa);
void zapiszDoPliku(char nazwiskoAutora[], Ksiazka tab[]);
void jakiGatunek(Ksiazka tab[]);
void sortowanie(Ksiazka tab[]);
void tablicaNaKonsole(Ksiazka tab[]);
// void odczytajPlik_zapiszDoTablicy()

int main()
{
    Ksiazka tab[N] = {};

    ifstream bookFile;
    bookFile.open("ksiazki.txt");

    if (bookFile.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            bookFile.getline(tab[i].tytul, 50);
        }
        for (int i = 0; i < N; i++)
        {
            bookFile.getline(tab[i].rodzaj, 20);
        }
        for (int i = 0; i < N; i++)
        {
            bookFile >> tab[i].rok_wydania;
        }
        bookFile.ignore();
        for (int i = 0; i < N; i++)
        {
            bookFile.getline(tab[i].autor.nazwisko, 20);
        }
        for (int i = 0; i < N; i++)
        {
            bookFile >> tab[i].autor.rok_urodzenia;
        }
    }
    else
    {
        cout << "Plik nie istnieje!";
    }
    bookFile.close();
    tablicaNaKonsole(tab);
    char wybranyAutor[20] = {};
    cout << endl << "Wprowadz wybranego autora, aby zapisac jego ksiazki do pliku tekstowego: ";
    cout << endl << "Dostepni autorzy: Lem, Sienkiewicz, Mickiewicz, Prus" << endl <<": ";
    cin >> wybranyAutor;
    zapiszDoPliku(wybranyAutor, tab);

    sortowanie(tab);

    jakiGatunek(tab);
    tablicaNaKonsole(tab);

    return 0;
}
void getPisarz(Pisarz nazwa)
{
    cout << nazwa.nazwisko << " urodzony/a w " << nazwa.rok_urodzenia << " roku." << endl;
}
void getKsiazka(Ksiazka nazwa)
{
    cout << "tytuł: " << nazwa.tytul << " - rok wydania " << nazwa.rok_wydania << ", rodzaj: " << nazwa.rodzaj << " autor: " << nazwa.autor.nazwisko << ", urodzony/a w " << nazwa.autor.rok_urodzenia << " roku";
}
void zapiszDoPliku(char nazwiskoAutora[], Ksiazka tab[])
{
    ofstream bookFile;
    bookFile.open("ksiazkiAutora.txt", ios::trunc);
    if(bookFile.is_open()) {
        for (int i = 0; i < N; i++) {
            if (strcmp(tab[i].autor.nazwisko, nazwiskoAutora)==0) {
                bookFile << tab[i].tytul << endl;
                bookFile << tab[i].autor.nazwisko << endl;
                bookFile << tab[i].rodzaj << endl ;
            }
        }
    }
    bookFile.close();
}
void jakiGatunek(Ksiazka tab[])
{
    char gatunek[20];
    cout << endl << "Wprowadz wybrany gatunek, aby wypisac ksiazki z wybranego gatunku w konsoli: ";
    cout << endl << "Dostepne gatunki: Tragedia, Powiesc, Nowela, Dramat, Epopeja" << endl << ": ";
    cin >> gatunek;
    cout << endl
         << "##### Ksiazki z gatunku " << gatunek << " #####" << endl;
    for (int i = 0; i < N; i++)
    {
        if (strcmp(tab[i].rodzaj, gatunek) == 0)
        {
            cout << "Tytul: " << tab[i].tytul << endl << " Nazwisko autora: " << tab[i].autor.nazwisko << endl << "---------" << endl;
        }
    }
    cout <<"**********************************************";
}
void sortowanie(Ksiazka tab[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N - i; j++)
        {
            if (strcmp(tab[j - 1].autor.nazwisko, tab[j].autor.nazwisko) > 0)
            {
                swap(tab[j - 1], tab[j]);
            }
        }
    }
    ofstream alf;
    alf.open("alfabetycznie.txt", ios::trunc);
    alf << "*****Książki w kolejnosci alfabetycznej*****\n";
    for (int i = 0; i < N; i++)
    {
        alf << endl
            << "=====Ksiazka numer " << i + 1 << "=====\n";
        alf << "Tytul: " << tab[i].tytul << endl;
        alf << "Gatunek: " << tab[i].rodzaj << endl;
        alf << "Rok wydania: " << tab[i].rok_wydania << endl;
        alf << "Nazwisko autora: " << tab[i].autor.nazwisko << endl;
        alf << "Rok urodzenia autora: " << tab[i].autor.rok_urodzenia << endl;
    }
    alf.close();
}
void tablicaNaKonsole(Ksiazka tab[])
{
    for (int i = 0; i < N; i++)
    {
        cout << endl
             << "=====Ksiazka numer " << i + 1 << "=====" << endl;
        cout << tab[i].tytul << endl;
        cout << tab[i].rodzaj << endl;
        cout << tab[i].rok_wydania << endl;
        cout << tab[i].autor.nazwisko << endl;
        cout << tab[i].autor.rok_urodzenia;
    }
}