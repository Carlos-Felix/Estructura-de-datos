#include <iostream>

using namespace std;

int main(){
    int* x;
    x = new int;
    *x = 5;
    int* y;
    y = x;
    cout << *x << endl;
    delete y;
    cout << *x << endl;
    return 0;
}