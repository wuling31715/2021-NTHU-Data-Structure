#include <iostream>
using namespace std;

void swap(int &a, int b) {
    int tmp = a;
    a = b;
    cout << a << " " << b << endl;
    b = tmp;
    cout << a << " " << b << endl;
}

int main() {
    int a = 0;
    int b = 1;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}