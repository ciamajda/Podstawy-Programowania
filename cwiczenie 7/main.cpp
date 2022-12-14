#include <iostream>
#include <ctime>
#include <iomanip>
//Wiktor Stępniewski
using namespace std;
const int N = 10;
void wierszNajwiekszaSuma(int tab[][N]);
void constructTablica(int tab[][N], int p, int k);
void tablicaNaKonsole(int tab[][N]);
void sortowanie(int A[][N], char typ, int w_kolumny);
void transpozycja(int tab[][N]);
bool czySymetryczna(int tablica[][N]);
void czySymetrycznaMSG(bool);
int **tworzenieTablicy(int &M, int &L);
void tablicaNaKonsole(int**, int, int);
void wypelnienieLosowe(int**, int, int);
void usuwanieTablicy(int**, int);
int main() {
    int A[N][N] = {}, p, k, AT[N][N]={}, w_kolumny = 0, M, L, zadanie;
    bool test, utworzenie=false;
    char typ;

    srand(time(NULL));
    while(zadanie!=9) {
        cout<<"Wybierz działanie: "<<endl
            <<"(1) symetryczne wypelnienie i wyswietlnie tablicy A"<<endl
            <<"(2) wyznacznie i wyswietlenie wierszy tablicy A z najwieksza suma"<<endl
            <<"(3) sprawdzanie symetrycznosci tablicy przed i po sortowaniu, sortowanie wybrancyh wierszy"<<endl
            <<"(4) transpozycja tabilcy A i wyswietlanie przed i po transpozycji"<<endl
            <<"(5) sprawdz czy tablica A jest symetryczna i wyswitel ja"<<endl
            <<"(6) stworz tablice dynamiczna"<<endl
            <<"(9) zakoncz program"<<endl
            <<"numer: ";
        cin>>zadanie;
        if (utworzenie == false && zadanie != 1 && zadanie!=6 && zadanie!=9) zadanie = 0; //dopisac tablice dynamiczna, ona nie wymaga
        switch (zadanie) {
            case 0: {
                cout << "Nie mozna wykonac dzialan na pustej tablicy!"<<endl;
                break;
            }
                //symetryczne wypelnienie i wyswietlnie tablicy A
            case 1: {
                cout << "Podaj liczbe p przedzialu liczbowy do wypelnienia tablicy <p,k>: " << endl;
                cin >> p;
                cout << "Podaj liczbe k przedzialu liczbowy do wypelnienia tablicy <p,k>: " << endl;
                cin >> k;
                constructTablica(A, p, k);
                utworzenie = true;
                break;
            }
            case 2: {
                wierszNajwiekszaSuma(A);
                break;
            }
            //sprawdzanie symetrycznosci tablicy przed i po sortowaniu, sortowanie wybrancyh wierszy
            case 3: {
                test = czySymetryczna(A);
                czySymetrycznaMSG(test);
                tablicaNaKonsole(A);
                while (w_kolumny != 10) {
                    cout << endl << "Wybierz indeks kolumny do sortowania: <0, 9>, aby zakonczyc sorotwnaie wybierz (10): ";
                    cin >> w_kolumny;
                    if(w_kolumny!=10) {
                        cout << endl << endl << "Podaj typ kolejnosc sortowania malejaca-m, rosnaca-r: ";
                        cin >> typ;
                        sortowanie(A, typ, w_kolumny);
                        cout << endl << "po sortowaniu" << endl;
                        tablicaNaKonsole(A);
                    }
                }
                break;
            }
            //transpozycja tabilcy A i wyswietlanie przed i po transpozycji
            case 4: {
                tablicaNaKonsole(A);
                transpozycja(A);
                break;
            }
            //sprawdzenie symetrycznosci tablicy A i wyswietlnie jej
            case 5: {
                tablicaNaKonsole(A);
                test = czySymetryczna(A);
                czySymetrycznaMSG(test);
                break;
            }
            //tworzenie tablicy dynamicznej
            case 6: {
                int **tablica = tworzenieTablicy(M, L);
                wypelnienieLosowe(tablica, M, L);
                tablicaNaKonsole(tablica, M, L);
                usuwanieTablicy(tablica, M);
                break;
            }
        }
    }
    return 0;
}
void wierszNajwiekszaSuma(int tab[][N]){
    int max = 0, maxp, wierszeSumy[N] = {};
    for (int i = 0; i < N; i++) {
        maxp = 0;
        for (int j = 0; j < N; j++) {
            maxp += tab[i][j];
        }
        wierszeSumy[i] = maxp;
        if (maxp > max) {
            max = maxp;
        }
    }
    cout << "wiersze tabeli z najwieksza suma (indeksy): ";
    int licznik = 0, wierszeIndeksy[N] = {};
    for (int i = 0; i < N; i++) {
        if (wierszeSumy[i] == max) {
            licznik++;
            cout << i << " ";
            wierszeIndeksy[i] = i;
        }
    }
    cout << endl << "Wypisanie wierszy z najwieksza suma: " << endl;
    for (int i = 0; i < N; i++) {
        if (wierszeIndeksy[i] != 0 || licznik > N - 1) {
            for (int j = 0; j < N; j++) {
                cout << tab[j][wierszeIndeksy[i]] << " ";
            }
            cout << endl;
        }
    }
//    }
}
void constructTablica(int tab[][N], int p, int k){
    int r=0, przejscie;
    for (int j = 0; j < N; j++) {
        for (int i = j; i < N; i++) {
            tab[j][i] = rand() % (k - p + 1) + p;
        }
    }
    for (int k = N - 1; k >= 0; k--) {
        r++;
        przejscie = N - r;
        for (int w = 0; w < przejscie; w++) {
            tab[k][w] = tab[w][k];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << tab[i][j];
        }
        cout << endl;
    }
}
void tablicaNaKonsole(int tab[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << tab[i][j];
        }
        cout << endl;
    }
}
void sortowanie(int A[][N], char typ, int w_kolumny){
    if (typ == 'r') {
        for (int j = 0; j < N; j++) {
            for (int i = 1; i < N - j; i++) {
                if (A[i - 1][w_kolumny] > A[i][w_kolumny]) swap(A[i - 1][w_kolumny], A[i][w_kolumny]);
            }
        }
    } else if (typ == 'm') {
        for (int j = 0; j < N; j++) {
            for (int i = 1; i < N - j; i++) {
                if (A[i - 1][w_kolumny] < A[i][w_kolumny]) swap(A[i - 1][w_kolumny], A[i][w_kolumny]);
            }
        }
    } else cout << "podano nieprawidlowy znak, nie wykonano sortowania";
}
void transpozycja(int tab[][N]){
    int tmp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = tab[j][i];
        }
    }
    cout << endl << "Transpozycja tablicy A: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << tmp[i][j];
        }
        cout << endl;
    }
}
bool czySymetryczna(int tablica[][N]) {
    int r = 0, przejscie;
    for (int k = N - 1; k >= 0; k--) {
        r++;
        przejscie = N - r;
        for (int w = 0; w < przejscie; w++) {
            if (tablica[k][w] == tablica[w][k]);
            else return false;
        }
    }
    return true;
}
void czySymetrycznaMSG(bool test){
    if (test == true) cout  << "symetryczna" << endl;
    else cout << "niesymetryczna" <<endl;
}
int **tworzenieTablicy(int &M, int &L){
    cout << "Podaj liczbe wierszy nowej tablicy: ";
    cin >> M;
    cout << "Podaj liczbe kolumn nowej tablicy: ";
    cin >> L;
    int **nowa = new int*[M];
    for (int i = 0; i < M; i++) {
        nowa[i] = new int[L];
    }
    return nowa;
}
void tablicaNaKonsole(int **tab, int M, int L){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < L; j++) {
            cout << setw(4) << tab[i][j];
        }
        cout << endl;
    }
}
void wypelnienieLosowe(int **tab, int M, int L){
    int granica;
    cout<<"Podaj granice wypelnienia (liczby naturalne): ";
    cin>>granica;
    for(int i=0; i<M; i++){
        for(int j=0; j<L; j++){
            tab[i][j]=rand()%granica;
        }
    }
}
void usuwanieTablicy(int **tablica, int M){
    for (int i = 0; i < M; i++){
        delete[] tablica[i];
    }
    delete [] tablica;
}