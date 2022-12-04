#include <iostream>
using namespace std;
void przelicz(int* wskG, int* wskM, bool MtoG){
    if(MtoG){
        *wskM = *wskG-621 + (*wskG - 621) / 32;
        cout<<"Rok "<<*wskG<<" w kalendarzu gregorianskim to rok "<<*wskM<<" w kalendarzu muzulmanskim";
    }
    else{
        *wskG = *wskM - *wskM / 33 + 621;
        cout<<"Rok "<<*wskM<<" w kalendarzu muzulmanskim to rok "<<*wskG<<" w kalendarzu gregorianskim";
    }

}
int main() {
    bool MtoG;
    char G_M;
    int M, G;
    cout<<"Przeliczanie daty z kalendarza gregorianskiego na kalendarz muzulmanski (G, g)" <<endl;
    cout<<"Przeliczanie daty z kalendarza muzulmanskiego na kalendarz gregorianski (M, m)" <<endl;
    cin>>G_M;
    if(G_M=='G' || G_M=='g'){
        cout<<"Podaj rok w kalendarzu gregorianskim: ";
        cin>>G;
        MtoG=true;
        przelicz(&G, &M, MtoG);
    }
    else if(G_M=='M' || G_M=='m') {
        cout << "Podaj rok w kalendarzu muzulmanskim: ";
        cin >> M;
        MtoG = false;
        przelicz(&G, &M, MtoG);
    }
    else{
        cout<<"Podano nieprawidlowy znak";

    }


    return 0;
}
