#include <iostream>
using namespace std;

void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    cout << "pivot: " << pivot << endl;
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            cout << arr[i] << " swap " << arr[j] << endl;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    cout << arr[i] << " swap " << arr[end] << endl;
    swap(&arr[i], &arr[end]);
    return i;
}

void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

int main() {
    int n = 9;
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "original:" << endl;
    PrintArray(arr, n);
    QuickSort(arr, 0, n-1);
    cout << "sorted:" << endl;
    PrintArray(arr, n);
    return 0;
}
