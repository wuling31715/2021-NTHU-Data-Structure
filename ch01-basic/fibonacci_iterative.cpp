#include <iostream>
using namespace std;

int fibonacci(int n) {
    int array[n];
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i < n; i++)
    {
        array[i] = array[i - 1] + array[i - 2];
        cout << array[i] << endl;
    }
    return array[n - 1];
}

int main(){
    int fn = fibonacci(10);
    cout << fn << endl;
}