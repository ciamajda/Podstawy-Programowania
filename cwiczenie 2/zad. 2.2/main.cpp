#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int liczba_gwiazdek, powtorzenie, liczba_gwiazdek_ostatnie_pow, n, liczba_gwiazdek_2, powtorzenie_2, liczba_gwiazdek_ostatnie_pow_2, x, y, p, h;
    cout << "podaj liczbe gwiazdek: ";
    cin >> liczba_gwiazdek;
    powtorzenie=0;
    x=liczba_gwiazdek;
    p=liczba_gwiazdek;
    h=liczba_gwiazdek;
    while(liczba_gwiazdek>0){
        liczba_gwiazdek_ostatnie_pow=0;
        powtorzenie++;
        for(int i=1; i<=powtorzenie && liczba_gwiazdek>0; i++){
                liczba_gwiazdek--;
                liczba_gwiazdek_ostatnie_pow++;
                cout<<"*";
        }
        cout<<'\n';
    }

    cout<<'\n';
    liczba_gwiazdek_2=liczba_gwiazdek;
    powtorzenie_2=powtorzenie;
    liczba_gwiazdek_ostatnie_pow_2=liczba_gwiazdek_ostatnie_pow;
    y=powtorzenie;


    while(1){
        if(liczba_gwiazdek_ostatnie_pow>0){
            while(liczba_gwiazdek_ostatnie_pow>0){
            cout<<"*";
            liczba_gwiazdek_ostatnie_pow--;
            liczba_gwiazdek++;
            }
        }
        else if(liczba_gwiazdek_ostatnie_pow==0 && powtorzenie!=1){
            for(int k=1; k<=powtorzenie;k++) {
            cout<<"*";
            liczba_gwiazdek++;
            }
        }

        else if(powtorzenie==1){
            cout<<"*";
            liczba_gwiazdek++;
            break;
        }

        cout<<'\n';
        powtorzenie--;;
    }

        cout<<'\n';
        cout<<'\n';

    int space=-1;
    while(1){
        if(liczba_gwiazdek_ostatnie_pow_2>0){
            while(liczba_gwiazdek_ostatnie_pow_2>0){
            cout<<"*";
            liczba_gwiazdek_ostatnie_pow_2--;
            liczba_gwiazdek_2++;
            }
        }
        else if(liczba_gwiazdek_ostatnie_pow_2==0 && powtorzenie_2!=1){
            for(int z=0; z<=space; z++){
                cout<<" ";
            }
            for(int l=1; l<=powtorzenie_2; l++) {
                cout<<"*";
                liczba_gwiazdek_2++;
            }
        }

        else if(powtorzenie_2==1){
            for(int z=0; z<=space; z++){
                cout<<" ";
            }
            cout<<"*";
            liczba_gwiazdek_2++;
            break;
        }

        cout<<'\n';
        powtorzenie_2--;;
        space++;


    }

    cout<<"\n";
    cout<<"\n";

        int powtorzenie_3 = 0, space_2 = y ;

        while(x>0){
        powtorzenie_3++;
            for(int b=1; b<space_2; b++){
                cout<<" ";

            }
            for(int i=1; i<=powtorzenie_3 && x>0; i++){
                x--;
                cout<<"*";
            }
            cout<<'\n';
            space_2--;
        }

        int powtorzenie_4 = -1;
        float space_3 = (sqrt(p))-1;


        int liczba_gwiazdek_3 = 0;
        int powtorzenia;
        int liczba_gwiazdek_ostatnie_pow_3;
        while (p > 0) {
            powtorzenie_4+=2;
            liczba_gwiazdek_ostatnie_pow_3=0;
            for (int i=0; i<=space_3; i++){
                cout<<" ";
            }
            for (int i = 1; i <= powtorzenie_4 && p > 0; i++) {
                liczba_gwiazdek_ostatnie_pow_3++;
                p--;
                cout << "*";

            }
            cout << '\n';
            space_3--;
            powtorzenia++;
        }
        cout << '\n';
        cout << '\n';

        int space_4 = -2;

       while(liczba_gwiazdek_3<h){
        space_4++;
        if(liczba_gwiazdek_ostatnie_pow_3>0){
            while(liczba_gwiazdek_ostatnie_pow_3>0){
            cout<<"*";
            liczba_gwiazdek_ostatnie_pow_3--;
            liczba_gwiazdek_3++;
            }
        }
        else if(liczba_gwiazdek_ostatnie_pow_3==0 && powtorzenia!=1){
            for(int z=0; z<=space_4; z++){
                cout<<" ";
            }
            for(int l=1; l<=powtorzenie_4; l++) {
                cout<<"*";
                liczba_gwiazdek_3++;
            }
        }

        else if(powtorzenie_4==1){
            while(int z=0<=space_4){
                z++;
                cout<<" ";
            }
            cout<<"*";
            liczba_gwiazdek_3++;
            break;
        }

        cout<<'\n';
        powtorzenie_4-=2;;



    }

}



