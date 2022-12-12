#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//cin.getline(zdanie, 50) funkcja pozwalajaca na wczytanie zdania ze spacjami
//strcmp(tekst1, tekst2)
//wesja bez wskaznika
using namespace std;
const int N=10;

struct Pisarz{
    int rok_urodzenia;
    char nazwisko[20];
};
struct Ksiazka{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz autor;
};
void wczytajDoTablicy(Ksiazka tab[]){

}
void getPisarz(Pisarz nazwa){
    cout<<nazwa.nazwisko<<" urodzony/a w "<<nazwa.rok_urodzenia<<" roku." <<endl;
}
void getKsiazka(Ksiazka nazwa){
    cout<<"tytuł: "<<nazwa.tytul<<" - rok wydania "<<nazwa.rok_wydania<<",rodzaj: "<<nazwa.rodzaj<<" autor: "<<nazwa.autor.nazwisko<<", urodzony/a w "<<nazwa.autor.rok_urodzenia<<" roku";
}
void zapiszDoPliku(string nazwiskoAutora, Ksiazka tab[]) {
    fstream bookFile;
    bookFile.open("ksiazki.txt", ios::app);
    for (int i = 0; i < N; i++) {
        if (nazwiskoAutora == tab[i].autor.nazwisko) {
            bookFile << tab[i].tytul << endl;
        }
    }
}

void jakiGatunek(Ksiazka tab[]){
    string gatunek;
    cout<<"Podaj gatunek: ";
    cin >> gatunek;
    for(int i=0; i<N; i++){
        if(tab[i].rodzaj==gatunek){
            cout<<tab[i].tytul<<" "<<tab[i].autor.nazwisko<<endl;
        }
    }
}
void sortowanie(Ksiazka tab[]){
    for(int i=0; i<N; i++){
        for(int j=1; j<N-i; j++){
            if(strcmp(tab[j-1].autor.nazwisko, tab[j].autor.nazwisko)>0){
                swap(tab[j-1], tab[j]);
            }
        }
    }
    ofstream alf;
    alf.open("alfabetycznie.txt");
    for(int i=0; i<N; i++){
        alf<<tab[i].tytul<<endl;
        alf<<tab[i].rodzaj<<endl;
        alf<<tab[i].rok_wydania<<endl;
        alf<<tab[i].autor.nazwisko<<endl;
        alf<<tab[i].autor.rok_urodzenia;
    }
    alf.close();

}
void tablicaNaKonsole(Ksiazka tab[]){
    for(int i=0; i<N; i++){
        cout<<endl<<tab[i].tytul<<endl;
        cout<<tab[i].rodzaj<<endl;
        cout<<tab[i].rok_wydania<<endl;
        cout<<tab[i].autor.nazwisko<<endl;
        cout<<tab[i].autor.rok_urodzenia;
    }
}
int main() {
    Ksiazka tab[N]={};
    fstream bookFile;
    bookFile.open("test.txt");
    if(bookFile.is_open()){
        cout<<"-----Tytuly ksiazek-----"<<endl;
        for(int i=0; i<N; i++){
            bookFile.getline(tab[i].tytul, 50);
            cout<<tab[i].tytul<<endl;
        }
        cout<<"-----Gatunki ksiazek-----"<<endl;
        for(int i=0; i<N; i++) {
            bookFile.getline(tab[i].rodzaj, 20);
            cout << tab[i].rodzaj<<endl;
        }
        cout<<"-----Rok wydania ksiazek-----"<<endl;
        for(int i=0; i<N; i++) {
            bookFile >>tab[i].rok_wydania;
            cout << tab[i].rok_wydania<<endl;
        }
        cout<<"-----Nazwiska autorow-----"<<endl;
        for(int i=0; i<=N; i++) {
            bookFile.getline(tab[i].autor.nazwisko, 20);
            cout << tab[i].autor.nazwisko<<endl;
        }
        cout<<"-----Daty urodzenia autorow-----"<<endl;
        for(int i=0; i<N; i++) {
            bookFile>>tab[i].autor.rok_urodzenia;
            cout << tab[i].autor.rok_urodzenia<<endl;
        }
//        for(int i=0; i<N; i++){
//            bookFile.getline(tab[i].tytul, 50);
//            bookFile.get();
//            bookFile.getline(tab[i].rodzaj, 20);
//            bookFile >>tab[i].rok_wydania;
//            bookFile.get();
//            bookFile.getline(tab[i].autor.nazwisko, 20);
//            bookFile>>tab[i].autor.rok_urodzenia;
//        }
//        tablicaNaKonsole(tab);
    }
    else{
        cout<<"Plik nie istnieje!";
    }
    bookFile.close();
//    zapiszDoPliku("\n cpp", tab);
    jakiGatunek(tab);
    zapiszDoPliku("Lem", tab);
    tablicaNaKonsole(tab);
    sortowanie(tab);
    tablicaNaKonsole(tab);
    return 0;
}