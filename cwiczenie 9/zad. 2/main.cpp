#include <iostream>
#include <fstream>
using namespace std;
struct pies{
    char imie[10];
    int wiek;
    double masa;
};
pies set1(){
    pies burek;
    cout<<"podaj imie psa: ";
    cin>>burek.imie;
    cout<<"podaj wiek psa: ";
    cin>>burek.wiek;
    cout<<"podaj mase psa: ";
    cin>>burek.masa;
    return burek;
}
pies set2(char imie[10], int wiek, double masa) {
    pies burek;
    strcpy(burek.imie, imie);
    burek.wiek = wiek;
    burek.masa = masa;
    return burek;
}
void get1(pies nazwa){
    cout<<endl<<"Pies "<<nazwa.imie<<" ma "<<nazwa.wiek<<" lat "<<"i wazy "<<nazwa.masa<<" kg";
}
int main() {
    pies pies_1, pies_2, pies_3;
    pies_1=set1();
    pies_2=set2("jurek", 8, 12.58);
    pies_3=set2("azor", 6, 25.65);
    pies pupile[3]={pies_1, pies_2, pies_3};

    for(int i=0; i<3; i++){
        get1(pupile[i]);
    }
    ofstream WRITE("imiona.txt");
    for(int i=0; i<3; i++) {
        WRITE << pupile[i].imie << endl;
    }
    WRITE.close();



    return 0;
}
