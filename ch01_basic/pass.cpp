#include <iostream>
using namespace std;

void call_by_value() {
    int i = 0;
    int j = i;
    i = 1;
    cout << i << " " << j << endl;
}

void call_by_reference() {
    int i = 0;
    int &j = i;
    i = 1;
    cout << i << " " << j << endl;
}

void call_by_pointer() {
    int i = 0;
    int &j = i;
    int* p = &j;
    i = 1;
    cout << p << " " << *p << endl;
}

int main() {
    call_by_value();
    call_by_reference();
    call_by_pointer();
    return 0;
}