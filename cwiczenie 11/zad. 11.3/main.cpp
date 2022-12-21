#include <iostream>
#include <bitset>
#include <fstream>
#include <string>

using namespace std;
const int N = 12; // Liczba znakow do zaszyfrowqania+1(znak konca)
void encrypt(char tab[], char klucz[])
{
    char enrypted[N] = {};
    int tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (tmp != 4 ?: tmp = 0)
        {
            enrypted[i] = tab[i] ^ klucz[tmp];
            tmp++;
        }
    }
    ofstream encryptedtxt;
    encryptedtxt.open("encrypted.txt", ios::trunc);
    if (encryptedtxt.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            encryptedtxt << enrypted[i];
        }
    }
    encryptedtxt.close();
}

int main()
{
    string test;
    char zdanie[N] = {}, klucz[4] = {};
    ifstream input, key;

    input.open("nowy.txt", ios::binary);
    if (input.is_open())
    {
        input.getline(&zdanie[0], N, '.');
    }
    else
        cout << "Plik nie istnieje.";
    input.close();

    key.open("klucz.txt");
    if (key.is_open())
    {
        key.getline(&klucz[0], 5, '.');
    }
    else
        cout << "Plik nie istnieje.";
    key.close();

    encrypt(zdanie, klucz);
    for (int i = 0; i < N; i++)
    {
        cout << zdanie[i];
    }

    return 0;
}
