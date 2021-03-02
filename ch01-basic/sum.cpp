#include <iostream>
using namespace std;

int sum(int n) {
    int array[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    for (int i = 0; i < n; i++) {
        total += array[i];
    }
    return total;
}

int main(){
    sum(10);
}