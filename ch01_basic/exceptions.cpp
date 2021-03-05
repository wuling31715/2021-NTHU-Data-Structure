#include <iostream>
using namespace std;

int main() {
    try {
        int age = 15;
        if (age >= 18) {
            cout << "Access granted." << endl;
        } else {
            throw age;
        }
    }
    catch (...) {
        cout << "Access denied." << endl;
    }
    return 0;
}
