#include <iostream>
using namespace std;

void sum(int n) {
    int array[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    for (int i = 0; i < n; i++) {
        total += array[i];
    }
    cout << total << endl;
}

int main(){
    sum(10);
}