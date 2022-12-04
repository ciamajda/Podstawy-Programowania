#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int rok;
    cout<<"Podaj dowolny rok: " <<endl;
    cin>> rok;

    if(rok%4==0 && rok%100!=0) {
        cout<<"Rok "<<rok<<" jest przestepny";
    }
    else if (rok%400==0){
        cout<<"Rok "<<rok<<" jest przestepny";
    }
    else {
        cout<<"Rok "<<rok<<" nie jest przestepny";
    }
}
