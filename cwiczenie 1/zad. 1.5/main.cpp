//Napisz program wczytujący wartości współczynników a, b i c i rozwiązujący równanie ax2 + bx + c = 0. Uwzględnij przypadek, gdy dla a = 0 równanie jest liniowe.

#include <iostream>

using namespace std;

int main() {
    float a, b, c, delta, x, x1, x2;
    cout<<"podaj wspolczynnik a: ";
    cin>>a;
    cout<<"podaj wspolczynnik b: ";
    cin>>b;
    cout<<"podaj wspolczynnik c:";
    cin>>c;
    delta=b*b-(4*a*c);

    if(a==0 && b!=0){
        cout<<"podana funkcja jest funkcja liniowa";
    }
    else if(a==0 && b==0 && c==0){
        cout<<"rownanie tozsamosciowe";
    }
    else{
        if (delta<0){
            cout<<"funkcja kwadratowa nie ma miejsc zerowych";
        }
        else if (delta==0){
            x=(-b)/2*a;
            cout<<"funkcja kwadratowa ma jedo powdojne rozwiazanie rowne: "<<x<<"";
        }
        else{
            x1=(-b)-delta/2*a;
            x2=(-b)+delta/2*a;
            cout<<"funkcja kwadratowa ma dwa rozwiazania równe: "<<x1<<" i "<<x2<<" ";

        }

    }


}
