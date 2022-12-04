#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float promien_kuli, promien_stozka, wys_stozka, objetosc_kuli, objetosc_stozka;
    cout<<"podaj promien kuli: ";
    cin>>promien_kuli;
    cout<<"podaj promien stozka: ";
    cin>>promien_stozka;
    cout<<"podaj wysokosc stozka: ";
    cin>>wys_stozka;

    objetosc_kuli=4/3.0*(M_PI*promien_kuli*promien_kuli*promien_kuli);
    cout<<"objetosc kuli jest rowna: "<<objetosc_kuli<<" "<<endl;

    objetosc_stozka=M_PI*promien_stozka*promien_stozka*wys_stozka;
    cout<<"objetosc stozka jest rowna: "<<objetosc_stozka<<""<<endl;
}
