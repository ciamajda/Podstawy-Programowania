//Wiktor Stępniewski
#include <iostream>
#include <ctime>
#include <cmath>
#define N 10
#define M 5
using namespace std;

void wypelnij(int tab[],int rozmiar, int p, int q);
void wypisz(int tab[], int rozmiar);
void npkwadraty(int tab[], int rozmiar,int &suma);
int maxtab(int tab[], int rozmiar, int &indeks);
void srednia(int tab[], int rozmiar, float &avg);
void odchylenie(int tab[], int rozmiar, float &odch, float srednia);
int iloczynSkalarny(int tab[], int tab2[],int rozmiar);
float wielomianSuma(float tab[],int rozmiar, int x);

int main() {
    srand(time(NULL));
    int X[N], Y[N], p, q, indeks=0, suma=0, x;
    float avg=0, odch=0, a1, a2, a3, a4, a5;
    cout<<"Podaj liczbe p (zakres <p, q>): ";
    cin>>p;
    cout<<"Podaj liczbe q (zakres <p, q>): ";
    cin>>q;
    wypelnij(X, N, p, q);
    wypelnij(Y,N, p, q);
    cout<<"Tablica X: ";
    wypisz(X, N);
    cout<<endl << "Tablica Y: ";
    wypisz(Y, N);
    cout<<endl << "Kwadraty tablicy X: ";
    npkwadraty(X, N, suma);
    cout<<endl<<"suma kwadratow: "<<suma;
    cout<<endl <<"Maksymalny element tablicy Y: ";
    cout<<maxtab(Y, N, indeks) << " pod numere indeksu " <<indeks << endl;
    srednia(X, N, avg);
    odchylenie(X, N, odch, avg);
    cout<<"Odchylenie standardowe tablicy X"<<odch<<endl;
    cout<<"Iloczyn skalarny X i Y: "<<iloczynSkalarny(X, Y, N)<<endl;
    cout<<"Podaj wspolcznynnik wielomianu a1: " <<endl;
    cin>>a1;
    cout<<"Podaj wspolcznynnik wielomianu a2: " <<endl;
    cin>>a2;
    cout<<"Podaj wspolcznynnik wielomianu a3: " <<endl;
    cin>>a3;
    cout<<"Podaj wspolcznynnik wielomianu a4: " <<endl;
    cin>>a4;
    cout<<"Podaj wspolcznynnik wielomianu a5: " <<endl;
    cin>>a5;
    cout<<"Podaj x dla w(x): ";
    cin>>x;
    float a[M]={a1, a2, a3, a4, a5};
    cout<<wielomianSuma(a, M, x);
    return 0;
}


void wypelnij(int tab[],int rozmiar, int p, int q) {
    for (int i = 0; i < rozmiar; i++) {
        tab[i] = rand() % (q-(p-1)) + p;
    }
}
void wypisz(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        cout << tab[i] <<" ";
    }
}
void npkwadraty(int tab[], int rozmiar, int &suma){
    int kw;
    for(int i=0; i<rozmiar; i++){
        if(tab[i]%2!=0){
            kw=tab[i]*tab[i];
            cout<<kw <<" ";
            suma+=kw;
        }

    }
}
int maxtab(int tab[], int rozmiar, int &indeks){
    int max=tab[0];
    for(int i=1; i<rozmiar;i++){
        if(tab[i]>max){
            max=tab[i];
            indeks=i;
        }
    }
    return max;
}
void srednia(int tab[], int rozmiar, float &avg){
    float iloscSrednia = N;
    for(int i=0; i<rozmiar; i++) {
        avg+=tab[i];
    }
    avg/=iloscSrednia;
}
void odchylenie(int tab[], int rozmiar, float &odch, float srednia){
    float iloscOdchylenie = N, suma;
    for(int i=0; i<rozmiar; i++){
        suma+=(tab[i]-srednia)*(tab[i]-srednia);
    }
    odch=suma/iloscOdchylenie;
}
int iloczynSkalarny(int tab[], int tab2[],int rozmiar){
    int skalar=0, sum;
    for(int i=0; i<rozmiar; i++){
        sum = tab[i]*tab2[i];
        skalar+=sum;
    }
    return skalar;
}
float wielomianSuma(float tab[],int rozmiar, int x){
    int wykladnik=0;
    float sumaWielomianu=0;
    for(int i=0;i<rozmiar;i++){
        sumaWielomianu+=pow(x, i)*tab[i];
        wykladnik++;
    }
    return sumaWielomianu;
}