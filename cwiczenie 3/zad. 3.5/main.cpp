#include <iostream>
using namespace std;
int reszta, mniejsza;
void algEuklidesa(int a, int b){
    if(b<a || a==b) {
        if (a % b == 0) {
            cout << "NWD a i b to " << b << " ";
        } else {
            while(a%b!=0){
                mniejsza = b;
                reszta = a % b;
                a=mniejsza;
                b=reszta;
            }
            cout << "NWD a i b to " << reszta << "";
        }
    }
    else{
        if(b % a == 0 ){
            cout << "NWD a i b to " << a << " ";
        }
        else{
            while(b%a!=0){
                mniejsza = a;
                reszta = b % a;
                b=mniejsza;
                a=reszta;
            }
            cout << "NWD a i b to " << reszta << "";

        }

    }
}


int main() {
    int a, b, reszta, mniejsza;

    cout<<"Podaj liczbe a: ";
    cin>>a;
    cout<<"Podaj liczbe b: ";
    cin>>b;
    algEuklidesa(a, b);
    cout<<'\n';


    return 0;
}
