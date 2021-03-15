#include <iostream>
using namespace std;

class Polynomial1 {
    private:
        int MaxDegree;
        
    public: 
        Polynomial1() {
            int degree;
            float coef[this -> MaxDegree + 1];
        }
};

class Polynomial2 {
    private:
        Term *termArray;
        int capacity;
        int terms; 
};

class Term {
    friend Polynomial2;
    private:
        float coef;
        int exp;
};