#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int N = 12;// Liczba znakow do zaszyfrowania+1(znak konca)
const int K = 4;//klucz

void encrypt(char tab[N], char safeKey[]);
void decrypt(char encrypted[], char safeKey[]);
void loadEncrypted (char (&encryptedTab)[]);
void loadTextToArray (char (&array)[], int textLength, string fileName);

int main() {
    char text[N] = {}, safeKey[K] = {}, encryptedTab[N] = {};

    loadTextToArray (text, N, "input.txt");

    loadTextToArray(safeKey, K, "key.txt");

    encrypt(text, safeKey);

    loadEncrypted(encryptedTab);

    decrypt(encryptedTab, safeKey);

    return 0;
}

void encrypt(char tab[N], char safeKey[])
{
    char encrypted[N] = {};
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (tmp != 4)
        {
            encrypted[i] = tab[i] ^ safeKey[tmp];
            tmp++;
        }
        else
        {
            tmp = 0;
            encrypted[i] = tab[i] ^ safeKey[tmp];
            tmp++;
        }
    }

    ofstream encryptedtxt;
    encryptedtxt.open("encrypted.txt", ios::trunc);
    if (encryptedtxt.is_open())
    {
        for (int i = 0; i < N - 1; i++)
        {
            encryptedtxt << encrypted[i];
        }
        encryptedtxt << '.';
    }
    encryptedtxt.close();
}

void decrypt(char encrypted[], char safeKey[])
{

    char decrypted[N] = {};
    int tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (tmp != 4)
        {
            decrypted[0] = encrypted[0] ^ safeKey[0];
            decrypted[i] = encrypted[i] ^ safeKey[tmp];
            tmp++;
        }
        else
        {
            tmp = 0;
            decrypted[i] = encrypted[i] ^ safeKey[tmp];
            tmp++;
        }
    }
    ofstream decryption;
    decryption.open("decryption.txt", ios::out);
    if (decryption.is_open())
    {
        for (int i = 0; i < N - 1; i++)
        {
            decryption << decrypted[i];
        }
        decryption << '.';
    }
}
void loadEncrypted (char (&encryptedTab)[])
{
    ifstream zaszyfrowane;
    zaszyfrowane.open("encrypted.txt", ios::binary);
    if (zaszyfrowane.is_open())
    {
        zaszyfrowane.getline(&encryptedTab[0], N);
    }
    else {
        cout << "Nie znaleziono pliku encrypted";
    }
    zaszyfrowane.close();
}

void loadTextToArray(char (&array)[], int textLength, string fileName)
{
    ifstream input;
    input.open(fileName, ios::binary);
    if (input.is_open())
    {
        input.getline(&array[0], textLength, '.');
    }
    else
    {
        cout << "Plik "<<fileName<<" nie istnieje.";
    }
    input.close();
}