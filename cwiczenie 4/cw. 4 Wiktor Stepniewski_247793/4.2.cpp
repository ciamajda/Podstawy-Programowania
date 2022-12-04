#include <iostream>
using namespace std;
void swap_2(int& first, int& second){
    int temp=first;
    first=second;
    second=temp;
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    int a=5, b=10;
    cout<<"Liczba a: "<<a<<" b: "<<b<<"" <<endl;

    swap(a,b);

    cout<<"Liczba a: "<<a<<" b: "<<b<<"" <<endl;

    swap_2(a,b);

    cout<<"Liczba a: "<<a<<" b: "<<b<<"";
    return 0;
}
