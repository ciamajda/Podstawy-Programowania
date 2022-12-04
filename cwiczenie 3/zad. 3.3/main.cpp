#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cout<<"podaj dokladnosc tablicy (skok) n w stopniach: ";
    cin>>n;
    double sinus, cosinus, tangens, ctangens, z;
    for(int i =0; i<=90; i+=n){
        z=(i*M_PI)/180;
        sinus = sin(z);
        cosinus = cos(z);
        tangens = sinus/cosinus;
        ctangens = cosinus/sinus;
        cout<<"sinus ("<<i<<" stopni): "<<sinus<<" cosinus ("<<i<<" stopni):  "<<cosinus<<" tangens ("<<i<<" stopni): "<<tangens<<" ctangens ("<<i<<" stopni):  "<<ctangens<<"" <<endl;
    }
    return 0;
}
