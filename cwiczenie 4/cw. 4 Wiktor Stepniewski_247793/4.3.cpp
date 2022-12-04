#include <iostream>
using namespace std;
int main() {
   int wynik, wynik_2, saldo=100, k=0;
    srand(time(NULL));
    for(int i =1; i<=10 && saldo>=20; i++){

        saldo-=20;
        wynik=rand()%11+2;
        cout<<"wyrzucono: "<<wynik<<" oczek" <<endl;
        if(wynik==7 || wynik==11){
            cout<<"Wygrana runda nr "<<i<<" -wyrzucono 7 lub 11" <<endl;
            saldo+=30;
        }
        else if(wynik==2 || wynik==3 || wynik==12){
            cout << "Przegrana runda nr "<<i<<" -wyrzucono 2, 3 lub 12" <<endl;
        }
        else if(wynik==4 || wynik==5 || wynik==6 || wynik==8 || wynik==9 || wynik==10){
            while(saldo>=20) {
                cout<<"Rzut do uzupelnienia punktów" <<endl;
                k++;
                saldo-=20;
                wynik_2=rand()%11+2;
                cout<<"wyrzucono "<<wynik_2<<" oczek" <<endl;
                if (wynik_2 == wynik) {
                    cout << "Wygrana runda nr "<<i<<"."<<k<<" -uzbierano punkty" <<endl;
                    saldo += 30;
                    break;
                } else if (wynik_2 == 7) {
                    cout << "Przegrana runda nr "<<i<<"."<<k<<" -wyrzucono 7 w drugim rzucie" <<endl;
                }
                else{
                    cout << "Przegrana runda nr "<<i<<"."<<k<<" -nie uzbierano punktow" <<endl;
                }
            }
        }

    }
    cout<<"Saldo końcowe = "<<saldo<<"" <<endl;
    return 0;
}
