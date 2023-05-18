#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Node{
    T data;
    struct Node<T>* next;
};

template<class T>
class Stack{

private:
    Node<T> *top;
    int size;
public:
    Stack(){
        top = NULL;
        size = 0;
    }
    void push(T value){
        Node<T> *temp = new Node<T>;
        temp->data = value;
        temp->next = top;
        top = temp;
        size++;
    }
    T pop(){
        T val = -1;
        if(top==NULL){
            cout << "Stack Empty" << endl;
            return val;
        }
        Node<T> *temp = top;
        top = top->next;
        size--;
        val = temp->data;
        delete temp;
        return val;
    }
    void display(){
        Node<T> *temp = top;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getSize(){
        return size;
    }
    T stackTop(){
        return top->data;
    }
    bool isEmpty(){
        return top==NULL;
    }
};

int main(){
    Stack<int> st;

    int operation = -1;
    while(operation != 5){
        cout << "Choose any operation from below: " << endl;
        cout << "1. Push Element" << endl;
        cout << "2. Pop Element" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Size of Stack" <<endl;
        cout << "5. Exit" << endl;

        cout << " Option : ";
        cin >> operation;

        if(operation==1){
            int element;
            cout << "Enter Element : ";
            cin >> element;

            st.push(element);
        }else if(operation==2){
            cout << "Element Removed : "<< st.pop() << endl;
        }else if(operation==3){
            cout << "Stack elements : ";
            st.display();
        }else if(operation==4){
            cout << "Stack Size : " << st.getSize() << endl;
        }
    }

    return 0;
}