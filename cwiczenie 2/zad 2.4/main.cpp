#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, silnia=1, i=1;
    float x, wartosc_y=0;
    cout<<"podaj N:";
    cin>>N;

    cout<<"podaj x: ";
    cin>>x;

    for(i=1; i<=N; i++){
        silnia*=i;
        wartosc_y+=pow(x, i)/silnia;

    }

    cout<<"Wartosc funkcji Y: "<<wartosc_y<<"";

    return 0;
}
