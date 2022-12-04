#include <iostream>
#include <ctime>
using namespace std;
const int N = 10;
int main()
{
    srand(time(NULL));
    char tab[N], litera;
    for (int i = 0; i < N; i++)
    {
        litera = rand() % ('z' - 'a' + 1) + 'a'; // od 98 do 122
        tab[i] = litera;
    }
    for (int i = 0; i < N; i++)
    {
        int *wskTab[i] = &tab[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << tab[i];
    }
    for (int i = 0; i < N; i++)
    {
        cout << *wskTab[i];
    }
    return 0;
}
