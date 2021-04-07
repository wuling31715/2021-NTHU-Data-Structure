#include <iostream>
using namespace std;

class Stack {
    private:
        int top;              
        int capacity;     
        int *stack;    
        
    public:
        Stack():
            top(-1), capacity(2) {
            stack = new int[capacity];
        }
        void Push(int x);
        void Pop();
        bool isEmpty();
        int getTop();
        int getSize();
};

void Stack::Push(int x) {
    if (top == capacity - 1) {
        cout << "Full" << endl;
        return;
    }
    stack[++top] = x;
}

void Stack::Pop() {
    if (isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    top--;      
}

bool Stack::isEmpty() {
       if (top == -1) {
           return true;
       }
       else {
           return false;
       }
}

int Stack::getTop() {
    if (isEmpty()) { 
        return -1;
    }
    return stack[top];
}

int Stack::getSize() {
    return top + 1;
}

int main(void) {
    Stack s;
    s.Push(0);
    s.Push(1);
    s.Push(2);
    cout << s.getTop() << endl;
    s.Pop();
    s.Push(3);
    cout << s.getTop() << endl;
    s.Pop();
    s.Pop();
    cout << s.getTop() << endl;
    return 0;
}