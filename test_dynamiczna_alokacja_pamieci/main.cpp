#include <iostream>
#include <iomanip>
using namespace std;
int main() {
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
    return 0;
}
