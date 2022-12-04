#include <iostream>
using namespace std;

int main() {

    int x, y, z;

    do {
        cout << "Podaj liczbe calkowita x: ";
        cin >> x;

        for (int i = 1; i <= x; i++) {
            if (x % i == 0) {
                cout << "" << i << ", ";
                z++;
            }

        }

        cout << '\n';

        if (z == 2) {
            cout << "Liczba " << x << " jest liczba pierwsza." <<endl;
        }

        cout << "Czy wznowic dzialanie programu? (1/0)" <<endl;
        cin >> y;
    } while (y==1);

    return 0;
}
