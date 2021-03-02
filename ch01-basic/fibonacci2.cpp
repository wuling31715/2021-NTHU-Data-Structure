#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int fn = fibonacci(10);
    cout << fn << endl;
}