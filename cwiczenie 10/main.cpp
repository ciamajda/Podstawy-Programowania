#include <iostream>
#include <fstream>
#include <string>
//cin.getline(zdanie, 50) funkcja pozwalajaca na wczytanie zdania ze spacjami
//strcmp(tekst1, tekst2)

const int N=10;
using namespace std;
struct Pisarz{
    int rok_urodzenia;
    char nazwisko[20];
};
struct Ksiazka{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz* autor;
};
void wczytajDoTablicy(Ksiazka tab[]){

}
void getPisarz(Pisarz nazwa){
    cout<<nazwa.nazwisko<<" urodzony/a w "<<nazwa.rok_urodzenia<<" roku." <<endl;
}
void getKsiazka(Ksiazka nazwa){
    cout<<"tytuł: "<<nazwa.tytul<<" - rok wydania "<<nazwa.rok_wydania<<", autor: "<<nazwa.autor->nazwisko<<", urodzony/a w "<<nazwa.autor->rok_urodzenia<<" roku";
}

int main() {
    Ksiazka tab[N];
    Pisarz lem;
    string test;
    lem.rok_urodzenia=2000;
    strcpy(lem.nazwisko, "Lem");
    getPisarz(lem);

    fstream bookFile;
    bookFile.open("ksiazki.txt");
    if(bookFile.is_open()){
        for(int i=0; i<3; i++){
            bookFile.getline(tab[i].tytul, 50);
            cout<<tab[i].tytul<<endl;
        }
        for(int i=3; i<6; i++) {
            bookFile.getline(tab[i].rodzaj, 20);
            cout << tab[i].rodzaj<<endl;
        }
        for(int i=6; i<9; i++) {
            tab[i].rok_wydania=bookFile.get();
            cout << tab[i].rodzaj<<endl;
        }

        bookFile.close();
    }
    else{
        cout<<"Plik nie istnieje!";
    }
    return 0;
}
