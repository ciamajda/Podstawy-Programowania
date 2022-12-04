#include <iostream>
using namespace std;

int liczbypit(int a, int b, int c) {

    if (a > b && a > c) {
        if (b * b + c * c == a * a) {
            return(1);
        }
        else {
            return(0);
        }
    }
    else if (b > a && b > c) {
        if (a * a + c * c == b * b) {
            return(1);
        }
        else {
            return(0);
        }
    }
    else if (c > a && c > b) {
        if (a * a + b * b == c * c) {
            return(1);
        }
        else {
            return(0);
        }
    }
    else{
        return(0);
    }
}

int main() {
    int a, b, c;
    cout << "Podaj liczbe a: ";
    cin >> a;
    cout << "Podaj liczbe b: ";
    cin >> b;
    cout << "Podaj liczbe c: ";
    cin >> c;
    liczbypit(a, b, c);
    cout << liczbypit(a, b, c) <<endl;
}



