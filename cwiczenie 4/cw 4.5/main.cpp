#include <iostream>
using namespace std;
void siodemkowy(int a){
    int tab[6], i=0;
    while(a/7>=1){
        tab[i]=a%7;
        a/=7;
        i++;
    }
    tab[i]=a%7;
    i++;
    cout<<"Liczba "<<a<<" w systemie siodemkowym to: ";
    for(int j = i-1; j>=0; j--){
        cout<<tab[j];
    }
}
int main() {
    int n;

        cout << "Podaj liczbe n (0 <= n <= 100 000): ";
        cin >> n;
        if (n >= 0 && n <= 100000) {
            siodemkowy(n);

        } else {
            cout << "Podano nieprawidlowy n";
        }

    return 0;
}
