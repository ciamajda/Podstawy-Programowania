#include <iostream> //dyrektywa preprocesowa, biblioteka dodajaca operacje wejsca wyjscia
#include <cmath>

using namespace std; //

int main()
{
    float stopnie, rad;
    cout<<"Podaj kat w stopniach:";
    cin>>stopnie;
    rad=stopnie*M_PI/180;
    cout<<"Kat w stopniach: "<<stopnie<<" to "<<rad<<" radianow";
    return 0;
}
