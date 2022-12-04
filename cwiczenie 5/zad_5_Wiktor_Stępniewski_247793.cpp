//Wiktor Stępniewski
#include <iostream>
#include <ctime>
#include <cstdlib>
#define ilosc_ocen 11
#define ilosc_uczniow 100
using namespace std;

//funckcja wypelniajaca tablice
void wypelnij(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        tab[i]=rand()%11;
    }
}
//funckcja wypisujaca tablice
void wypisz(int tab[]) {
    for(int i = 0; i < ilosc_uczniow; i++){
        cout<<tab[i] << ", ";
    }
}
//funckcja obliczajaca srednia
float srednia(int tab[]){
    float avg;
    for(int i = 0; i < ilosc_uczniow; i++){
        int suma;
        suma+=tab[i];
        avg=(suma/ilosc_uczniow);
    }
    return avg;
}
//funckcja obliczajaca mediane
float mediana(int tab[]){
    float med;
    int srd, srd2, srdnp;
    srd2=(ilosc_uczniow/2)-1;
    srd=ilosc_uczniow/2;
    srdnp=((ilosc_uczniow+1)/2)-1;
    if(ilosc_uczniow%2==0){
        med=(tab[srd]+tab[srd2])/2.0;
        return med;
    }
    else{
        med=(tab[srdnp]);
        return med;
    }
}
//funckcja obliczajaca ilosc danej oceny
void zlicz(int tab[], int tab2[]){
    for(int i =0; i<ilosc_uczniow; i++){
        for(int j=0; j<=10; j++){
            if(j==tab[i]){
                tab2[j]+=1;
            }
            else{}
        }
    }
}
//funckcja wyswietlajaca liczbe poszczegolnych ocen
void wyswietl_oceny(int tab[]){
    for(int i=0; i<ilosc_ocen; i++){
        cout<<"Liczba ocen: "<<i<<" jest rowna: "<<tab[i] <<endl;
    }
}
//funkcja zerujaca tablice
void wyzeruj_tabele(int tab[], int elementy_tablicy){
    for(int i=0; i<ilosc_ocen; i++){
        tab[i]=0;
    }
}
//funkcja rysujaca histogram
void rysuj_histogram(int tab[]){
    for(int i=0; i<ilosc_ocen; i++){
        cout<<"Ilosc ocen "<<i<<":  ";
        for(int j=0; j<tab[i]; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
//funkcja szukajaca ocen, ktore pojawily sie z najwieksza czestotliwoscia
void najwiekszy_element(int tab[], int elementy_tablicy){
    int max, ilosc_max;
    max=tab[0];
    ilosc_max=1;
    for(int i=1; i<=elementy_tablicy; i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    for(int i=0; i<elementy_tablicy; i++) {
        if (max == tab[i]) {
            if (ilosc_max == 1) {
                cout << "Najwiecej razy (" << max << ") przyznano ocene " << i << "";
            } else {
                cout << ", oraz ocene " << i << "";
            }
            ilosc_max++;
        }

    }
    cout<<endl;
}



int main() {

    srand(time(NULL));
    int oceny[ilosc_uczniow], liczba_ocen[ilosc_ocen];
    wypelnij(oceny, ilosc_uczniow);
    cout<<"Elementy tablicy (oceny): ";
    wypisz(oceny); cout <<endl;
    cout<<"Srednia ocen: "<<srednia(oceny)<<"" <<endl;
    cout<<"Mediana ocen: "<<mediana(oceny)<<"" <<endl;
    wyzeruj_tabele(liczba_ocen, ilosc_ocen);
    zlicz(oceny, liczba_ocen);
    wyswietl_oceny(liczba_ocen);
    najwiekszy_element(liczba_ocen, ilosc_ocen);
    rysuj_histogram(liczba_ocen);

    return 0;
}
