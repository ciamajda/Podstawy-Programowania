#include <iostream>
#include <bitset>
using namespace std;

int encrypt(char tab[4]){
    unsigned int encryptedChar=0, tmp;
    for(int i=0; i<4; i++){
        if(i!=3) {
            encryptedChar += tab[i];
            encryptedChar <<= 8;
        }
        else{
            encryptedChar += tab[i];
        }
    }
    return encryptedChar;
}
void decrypt(int encryptedInt, char tab[4]){
    unsigned short tmp;
    for(int i=3; i>=0; i--) {
        tab[i]=encryptedInt;
        encryptedInt>>=8;
    }
    for(int i=0; i<4; i++){
        cout<<tab[i]<<" ";
    }
}
int main() {
    char tab[4]={'A', 's', 'p', 'z'}, decrypted[4];
    unsigned int encryptedChar=0;
    cout<<bitset<32>(encryptedChar)<<endl;
    encryptedChar=encrypt(tab);
    cout<<bitset<32>(encrypt(tab))<<endl;
    decrypt(encryptedChar, decrypted);
    return 0;
}
