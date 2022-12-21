#include <iostream>
#include <bitset>
using namespace std;
char *encrypt(char zdanie[], char key[]){
    char encryptedArr[]={};
    int j=0;
    for(int i=0; i<12; i++) {
        if(j>3 ? j=0 : NULL) {
            encryptedArr[i] = (zdanie[i] ^ key[j]);
            j++;
        }
    }
    return encryptedArr;
}

int main() {
    char tab[12]={"Ala ma kota"}, key[4]={'a', 'b', 'c', 'd'}, encryptedArr[12]={};

    char *a=encrypt(tab, key);
    cout<<encrypt(tab, key);
    for(int i=0; i<11; i++){
        cout<<tab[i];
    }
    cout<<endl;
//    cout<<*a<<endl;
    for(int i=0; i<11; i++){
        cout<<encryptedArr[i];
    }
    cout<<encrypt(tab, key);
    return 0;
}
