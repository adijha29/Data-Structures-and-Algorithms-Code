#include <bits/stdc++.h>

using namespace std;

template<class T>
class Stack{

private:
    T *st;
    int top;
    int size;

public:
    Stack(){
        top = -1;
        size = 1;
        st = new T[size];
    }
    
    Stack(int n){
        size = n;
        top = -1;
        st = new T[size];
    }

    void push(T x);
    T pop();
    T peek(int index);
    T stackTop();
    bool isEmpty();
    bool isFull();
    void display();
};

template<class T>
void Stack<T> :: push(T x){
    if(isFull()){
        cout << "Stack OverFlow !!!" << endl;
    }else{
        top++;
        st[top] = x;
    }
}

template<class T>
T Stack<T> :: pop(){
    T x = -1;
    if(isEmpty()){
        cout << "Stack UnderFlow !!" << endl;
    }
    else{
        x = st[top];
        top--;
    }
    return x;
}

template<class T>
T Stack<T> :: peek(int index){
    T x = -1;
    if(top - index + 1 < 0){
        cout << "Invalid Index .." << endl;
    }else{
        x = st[top-index+1];
    }
    return x;
}

template<class T>
T Stack<T> :: stackTop(){
    if(isEmpty()){
        cout << "Stack is Empty ..." << endl;
        return -1;
    }
    return st[top];
}

template<class T>
bool Stack<T> :: isFull(){
    return top == size-1;
}

template<class T>
bool Stack<T> :: isEmpty(){
    return top == -1;
}

template<class T>
void Stack<T> :: display(){
    for(int i=top;i>=0;i--){
        cout << st[i] << " ";
    }
    cout << endl;
}

int main(){
    string s;
    cout << "Enter Infix Expression : ";
    cin >> s;

    Stack<char> st(s.size());

    
    // Checking if Stack is Empty
    printf("isEmpty() : %d\n\n",st.isEmpty());

    // Checking UnderFlow Conditions
    printf("stackTop() : ");
    st.stackTop();
    printf("\n\n");

    printf("Pop(): ");
    st.pop();
    printf("\n\n");

    // Invalid Index
    printf("Peek(5) : ");
    st.peek(5);
    printf("\n\n");

    for(char i='a';i<'a'+10;i++){
        st.push(i);
        printf("st.push(%c)\n",i);
    }

    printf("\n\n");

    // Display Stack Elements
    printf("display() : ");
    st.display();
    printf("\n\n");

    
    // Checking if Stack is Full
    printf("isFull() : %d\n\n",st.isFull());

    // Stack Top 
    printf("StackTop() : %d",st.stackTop());
    printf("\n\n");

    // OverFlow Condition
    printf("push(z) : ");
    st.push('z');
    printf("\n\n");

    // Stack Pop
    printf("pop() : ");
    char element = st.pop();
    printf("%c\n\n",element);

    // Stack Peek
    printf("peek(3) : %c",st.peek(3));
    
    return 0;
}