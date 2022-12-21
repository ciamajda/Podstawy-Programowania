#include <iostream>
#include <bitset>
using namespace std;
//cout<<bitset<8>(a)
void wlacz_bit(unsigned int &nazwaZmiennej, int nrBitu){
    nazwaZmiennej = nazwaZmiennej | (1 << nrBitu);
}
void wylacz_bit(unsigned int &nazwaZmiennej, int nrBitu){
    nazwaZmiennej = nazwaZmiennej ^ (1 << nrBitu);
}
void zmien_bit(unsigned int &nazwaZmiennej, int nrBitu){
    nazwaZmiennej = nazwaZmiennej ^ (1 << nrBitu);
}
bool bit_wylaczony(unsigned int nazwaZmiennej, int nrBitu){
    unsigned int tmp=0;
    tmp = nazwaZmiennej ^ (1 << nrBitu);
    if (tmp==nazwaZmiennej) return true;
    else return false;
}

int main() {
    unsigned int a=0, b=3, c=7;
    cout<<"Liczba a przed zmiana: "<<bitset<8>(a)<<endl;
    wlacz_bit(a, 0);
    cout<<"Liczba a po zmiana: "<<bitset<8>(a)<<endl;
    cout<<"Liczba b przed zmiana: "<<bitset<8>(b)<<endl;
    wylacz_bit(b, 0);
    cout<<"Liczba b po zmiana: "<<bitset<8>(b)<<endl;
    cout<<"Liczba c przed zmiana: "<<bitset<8>(c)<<endl;
    zmien_bit(c, 1);
    cout<<"Liczba c po zmiana: "<<bitset<8>(c)<<endl;
    if(bit_wylaczony(c, 1)) cout<<"Bit nr 1 jest rowny zero"<<endl;
    else cout<<"Bit nr 1 nie jest rowny zero"<<endl;
    return 0;
}
