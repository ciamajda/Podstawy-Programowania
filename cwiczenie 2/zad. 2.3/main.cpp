//zad 2.3 Wiktor StÍpniewski

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, eps, i=1, silnia=1, n=1;
    double wartosc = 1;

    cout<<"Podaj x do obliczenia exp(x): ";
    cin>>x;

    cout<<"Podaj epsilon: ";
    cin>>eps;

    while(fabs(pow(x, i)/silnia)>eps){
        for(int k=1; k<=n; k++){
            silnia*=k;
        }

        wartosc+=pow(x, i)/silnia;
        n++;
        i++;
    }

    cout<<"Wartosc wyrazenia exp("<<x<<") jest rowna: "<<wartosc<<"" <<endl;

    return 0;
}
