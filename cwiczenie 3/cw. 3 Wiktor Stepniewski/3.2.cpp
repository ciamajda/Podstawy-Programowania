//Wiktor Stępniewski
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    double kat, sinus, kat_2;
    char jednostka;
    cout<<"Podaj jednostke miary: stopnie(S, s), radiany(R, r): ";
    cin>>jednostka;
    cout<<"Podaj wartosc kata aby obliczyc jego sinus: ";
    cin>>kat;


    switch (jednostka){
        case('S'):
        case('s'):
            kat_2=(kat*M_PI)/180.0;
            sinus= sin(kat_2);
            cout<<"Sinus kata o miarze "<<kat<<" stopni wynosi "<<sinus<<"";
            break;
        case('R'):
        case('r'):
            sinus= sin(kat);
            cout<<"Sinus kata o miarze "<<kat<<" rad wynosi "<<sinus<<"";
            break;
        default:
            cout<<"Podano niepoprawne wartosci";

    }
    return 0;
}
