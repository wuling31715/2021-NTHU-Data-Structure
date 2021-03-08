#include <iostream>
using namespace std;

class Employee {
    private:
        int salary;
    public:
        Employee() {
            setSalary(100);
        }
        void setSalary(int n) {
            this -> salary = n;
            }
        void addSalary(int n) {
            this -> salary += n;
        }
        int getSalary() { 
            return this -> salary;
            }
};

class Programmer: public Employee {
    public:
        Programmer() {
            setSalary(500);
        }
};

class Manager: public Employee {
    public:
        Manager() {
            setSalary(1000);
        }
        void bonusSalary(int n) {
            int salary;
            salary *= n;
        }
};

int main() {
    Employee e;
    Programmer p;
    Manager m;
    p.addSalary(500);
    m.bonusSalary(2);
    cout << e.getSalary() << endl;
    cout << p.getSalary() << endl;
    cout << m.getSalary() << endl;
    return 0;
}