#include <iostream>
using namespace std;
struct osoba{
    char imie[10];
    char nazwisko[20];
    int wiek;
};

int main() {
    osoba human;
    cout<<"Podaj imie osoby: ";
    cin>>human.imie;
    cout<<"Podaj nazwisko osoby: ";
    cin>>human.nazwisko;
    cout<<"Podaj wiek osoby: ";
    cin>>human.wiek;
    cout<<"Imie: "<<human.imie;
    cout<<endl<<"Nazwisko: "<<human.nazwisko;
    cout<<endl<<"Wiek: "<<human.wiek<<"";

    return 0;
}
