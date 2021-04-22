#include<iostream>
using namespace std;

void DDArray(int **a, int x,int y) {
    int i,j;
    for (i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    int r = 2, c = 2, i, j;
    int** arr = new int* [r];
    for(i = 0; i < r; i++) {
        arr[i] = new int[c];
    }

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cout << "Enter element at position " << i + 1 << j + 1;
            cin>>arr[i][j];
        }
    }
    DDArray(arr, r, c);
}