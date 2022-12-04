#include <iostream>
#include <iomanip>
using namespace std;
int silniaN(int n){
    if(n<=1){
        return (1);
    }
    return n*silniaN(n-1);
}

int main() {
    int n, silnia=1, k, z;
    double dwumian;
    cout<<"Podaj n: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        silnia*=i;
    }
    cout<<silnia <<endl;

    cout<<silniaN(n) <<endl;

    //dwumian newtona

    cout<<"Podaj wyraz k dwumianu newtona: ";
    cin>>k;
    z=n-k;
    dwumian=silniaN(n)/(silniaN(k)*silniaN(z));
    cout<<dwumian;

    //trojkat pascala
    int lw, lw_2=0;
    cout<<"Podaj liczbe wierszy w torjkacie pascala: ";
    cin>> lw;
    for(int i=0; i<lw-1; i++){
        lw_2+=2;
    }


    for(int i=0; i<lw; i++){
        for(int k=1; k<lw-i; k++){
            cout<<"  ";
        }
        for(int j=0; j<i; j++){
            int x=i-j;
            cout<<silniaN(i)/(silniaN(j)*silniaN(x)) << "   ";
        }
        cout<<1;
        cout<< endl;
        lw_2-=2;
    }


    return 0;
}
