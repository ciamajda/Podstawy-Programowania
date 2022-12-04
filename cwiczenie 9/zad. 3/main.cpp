#include <iostream>
using namespace std;
struct Pisarz
{
    int rok_urodzenia;
    char imie[12];
    char nazwisko[20];
};
struct Ksiazka
{
    char tytul[20];
    int rok_wydania;
    Pisarz *autor;
};
Pisarz fillPisarz(int rok_urodzenia, char imie[12], char nazwisko[20])
{
    Pisarz magik;
    magik.rok_urodzenia = rok_urodzenia;
    strcpy(magik.imie, imie);
    strcpy(magik.nazwisko, nazwisko);
    return magik;
}
Ksiazka fillKsiazka(char tytul[20], int rok_wydania, Pisarz *autor)
{
    Ksiazka nazwa;
    strcpy(nazwa.tytul, tytul);
    nazwa.rok_wydania = rok_wydania;
    nazwa.autor=autor;
    return nazwa;
}
void getPisarz(Pisarz nazwa){
    cout<<nazwa.imie<<" "<<nazwa.nazwisko<<" urodzony w "<<nazwa.rok_urodzenia<<" roku.";
}
void getKsiazka(Ksiazka name){
    cout<<"Tytul: "<<name.tytul<<" -rok wydania "<<name.rok_wydania<<", autor "<<name.autor->imie<<" "<<name.autor->nazwisko<<" rok urodzenia: "<<name.autor->rok_urodzenia;
}
int main()
{
    Pisarz adam, boleslaw, william;
    adam = fillPisarz(1798, "Adam", "Mickiewicz");
    boleslaw = fillPisarz(1847, "Boleslaw", "Prus");
    william = fillPisarz(1564, "William", "Shakespeare");
    Pisarz autorzy[3] = {adam, boleslaw, william};
    Ksiazka tadeusz, lalka, makbet, hamlet;
    tadeusz = fillKsiazka("Pan Tadeusz", 1834, &autorzy[2]);
    lalka = fillKsiazka("Lalka", 1890, &autorzy[1]);
    makbet = fillKsiazka("Makbet", 1606, &autorzy[0]);
    hamlet = fillKsiazka("Hamlet", 1602, &autorzy[0]);
    Ksiazka tabKs[4] = {tadeusz, lalka, makbet, hamlet};
    for(int i=0; i<3; i++){
        getPisarz(autorzy[i]);
        cout<<endl;
    }
    for(int i=0; i<4; i++){
        getKsiazka(tabKs[i]);
        cout<<endl;
    }
    return 0;
}
