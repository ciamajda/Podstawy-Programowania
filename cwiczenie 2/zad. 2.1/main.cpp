#include <iostream>
using namespace std;

int main() {
    int n, w;
    cout<<"podaj liczbe n: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        cout<<""<<i<<", ";
    }

    cout<<'\n';

    for(int i=n; i<=n && i>0; i--){
        cout<<""<<i<<", ";
    }

    cout<<'\n';

    for(int i=1; i<n; i++){
        if(i%2!=0){
            cout<<""<<i<<", ";
        }

    }

    cout<<'\n';

    for(int i=1; i<n; i++){
        if(i%2==0){
            if(i%3==2){
                cout<<""<<i<<", ";
            }
            else{

            }
        }
        else{

        }

    }

    cout<<'\n';

    for(int i=1; i<n; i++){
        if(i%5==0){
            cout<<""<<i<<", ";
        }
        else{

        }
    }

    for(int i='a'; i<='z'; i++){
        char litera = i;
        cout<<litera;
    }


        return 0;
}
