#include <iostream>
#include <cmath>
using namespace std;
int main() {
    char figura;
    float db, kb, at, ht, r, pole_prostokata, pole_trojkata, pole_kola;
    cout<<"Podaj jakiej figury pole chcesz obliczyc: prostokat(P, p), trojkat(T, t), koło(K, k): ";
    cin>>figura;

    switch (figura){
        case ('P'):
        case ('p'):
            cout<<"Podaj dlugosc dluzszego boku prostokata: ";
            cin>>db;
            cout<<"Podaj dlugosc krotszego boku prostokata: ";
            cin>>kb;
            pole_prostokata=db*kb;
            cout<<"Pole prostokata o wymiarach "<<kb<<"x"<<db<<" wynosi: "<<pole_prostokata<<"";
            break;
        case ('t'):
        case ('T'):
            cout<<"Podaj dlugosc podstawy trojkata: ";
            cin>>at;
            cout<<"Podaj wysokosc trojkata: ";
            cin>>ht;
            pole_trojkata=(at*ht)/2;
            cout<<"Pole trojkata o podstawie: "<<at<<" i wysokosci: "<<ht<<" wynosi: "<<pole_trojkata<<"";
            break;
        case ('k'):
        case ('K'):
            cout<<"Podaj promien kola: ";
            cin>>r;
            pole_kola=M_PI*r*r;
            cout<<"Pole kola o promieniu: "<<r<<" wynosi: "<<pole_kola<<"";
            break;
        default:
            cout<<"Podano niepoprawne wartosci";


    }
    return 0;
}
