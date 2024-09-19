#include <iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;
    
    // Constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    
    // Destructor to release allocated memory
    ~Stack() {
        delete[] arr;
    }
    
    // Push element onto the stack
    void push(int element) {
        if (top < size - 1) { // Stack is not full
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }
    
    // Pop element from the stack
    void pop() {
        if (top >= 0) { // Stack is not empty
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }
    
    // Peek at the top element
    int peek() {
        if (top >= 0) { // Stack is not empty
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1; // Or you can throw an exception if preferred
        }
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack st(5);
    st.push(22);
    st.push(32);
    st.push(42);
    st.push(52);
    st.push(62);
    
    cout << st.peek() << endl; // Should output 62
    
    st.pop();
    cout << st.peek() << endl;
	
	cout<<st.isEmpty(); // Should output 52
    
    return 0;
}

