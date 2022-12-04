#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    int x, y, z, suma;
    float srednia_arytmetyczna, srednia_harmoniczna;
    cout<<"podaj x: ";
    cin>>x;
    cout<<"podaj y: ";
    cin>>y;
    cout<<"podaj z: ";
    cin>>z;
    suma=x+y+z;
    cout<<"suma = "<<suma<<"" <<endl;
    srednia_arytmetyczna=suma/3.0;
    cout<<"srednia arytmetyczna = "<<srednia_arytmetyczna<<""<<endl;
    srednia_harmoniczna=3/((1.0/x)+(1.0/y)+(1.0/z));
    cout<<"srednia harmoniczna = "<<srednia_harmoniczna<<""<<endl;

}
