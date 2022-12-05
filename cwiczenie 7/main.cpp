#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
const int N = 5;

void transpozycja(int tab[][N],int tabT[][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabT[i][j] = tab[j][i];
        }
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
    if (test == true) cout << "symetryczna";
    else cout << "niesymetryczna" <<endl;
}


int main() {
    int A[N][N] = {}, p, k, AT[N][N]={};
    bool test;
    char typ;
    srand(time(NULL));
    cout << "Podaj liczbe p przedzialu liczbowy do wypelnienia tablicy <p,k>: " << endl;
    cin >> p;
    cout << "Podaj liczbe k przedzialu liczbowy do wypelnienia tablicy <p,k>: " << endl;
    cin >> k;
    //wypelnienie tablicy
    for (int j = 0; j < N; j++) {
        for (int i = j; i < N; i++) {
            A[j][i] = rand() % (k - p + 1) + p;
        }
    }
    //wyswietlenie tablicy
    cout << "Tablica losowa wypelniona powyzej przekatnej: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    //symetryczne wypelnienie
    int r = 0, przejscie;
    for (int k = N - 1; k >= 0; k--) {
        r++;
        przejscie = N - r;
        for (int w = 0; w < przejscie; w++) {
            A[k][w] = A[w][k];
        }
    }
    cout << endl << endl << "Symetryczne dopelniona tablica A: " << endl;
    //wyswitlniene tablicy symetrcznej
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    //wiersz ktorego suma ma najwieksza wartosc
    int max = 0, maxp = 0, wier[N] = {};
    for (int i = 0; i < N; i++) {
        maxp = 0;
        for (int j = 0; j < N; j++) {
            maxp += A[i][j];
        }
        wier[i] = maxp;
        if (maxp > max) {
            max = maxp;
        }
    }
    cout << "wiersze tabeli z najwieksza suma (indeksy): ";
    int licznik = 0, wiersze[N] = {};
    for (int i = 0; i < N; i++) {
        if (wier[i] == max) {
            licznik++;
            cout << i << " ";
            wiersze[i] = i;
        }
    }
    cout << endl << "Wypisanie wierszy z najwieksza suma: " << endl;
//    for(int i=0; i<licznik; i++){
    for (int i = 0; i < N; i++) {
        if (wiersze[i] != 0 || licznik > N - 1) {
            for (int j = 0; j < N; j++) {
                cout << A[j][wiersze[i]] << " ";
            }
            cout << endl;
        }
    }
//    }
//    //sprawdzenie symetrycznosci dla A przed sortowaniem
    test = czySymetryczna(A);
    czySymetrycznaMSG(test);
//    sortowanie kolumn
//    sortowanie rosnace

    int w_kolumny = 0;
    cout << endl << "Wybierz indeks kolumny do sortowania: <0, 9>: ";
    cin >> w_kolumny;
    cout << endl << endl << "Podaj typ kolejnosc sortowania malejaca-m, rosnaca-r: ";
    cin >> typ;

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
    cout << endl << "po sortowaniu" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }
    //transpozycja A
    transpozycja(A, AT);
    //wyswietlenie AT
    cout << endl << "Transpozycja tablicy A: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << AT[i][j] << " ";
        }
        cout << endl;
    }
    test = czySymetryczna(A);
    czySymetrycznaMSG(test);

    int M, L;
    cout << "Podaj liczbe wierszy nowej tablicy: ";
    cin >> M;
    cout << "Podaj liczbe kolumn nowej tablicy: ";
    cin >> L;
    int **nowa = new int*[M];
    for (int i = 0; i < M; i++) {
        nowa[i] = new int[L];
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<L; j++){
            nowa[i][j]=rand()%11;
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<L; j++){
            cout<<setw(4)<<nowa[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < M; i++){
        delete[] nowa[i];
    }
    delete [] nowa;
    return 0;//zmiana git
}