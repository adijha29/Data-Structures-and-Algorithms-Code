#include <bits/stdc++.h>

using namespace std;

// Doubly Linked List Node
template<class T>
struct Node{
    struct Node<T> *prev;
    T data;
    struct Node<T> *next;
};

template <class T>
class DoublyLL{
private:
    Node<T>* head;
public:
    DoublyLL(){
        head = NULL;
    }
    
    void insertNode(int pos, T value){
        if(pos < 0 || pos > countNode()){
            return;
        }
        Node<T>* t;
        t = new Node<T>();
        t->data = value;
        t->prev = t->next = NULL;
        if(pos==0){
            t->next = head;
            head->prev = t;
            head = t;
        }
        else{
            Node<T>* p = head;
            for(int i=0;i<pos-1;i++){
                p = p->next;
            }
            t->prev = p;
            t->next = p->next;
            if(p->next)p->next->prev=t;
            p->next = t;
        }
    }
    
    T deleteNode(int idx){
        if(idx < 0 || idx >= countNode()){
            return -1;
        }
        T val;
        Node<T> *temp1;
        if(idx==0){
            temp1 = head;
            head = head->next;
            if(head)head->prev = NULL;
            val = temp1->data;
            delete temp1;
        }
        else{
            temp1 = head;
            for(int i=0;i<idx-1;i++){
                temp1 = temp1->next;
            }
            temp1->prev->next = temp1->next;
            if(temp1->next){
                temp1->next->prev = temp1->prev;
            }
            val = temp1->data;
            delete temp1;
        }
        return val;
    }

    int countNode(){
        Node<T>* p = head;
        int count = 0;
        while(p!=NULL){
            count++;
            p = p->next;
        }
        return count;
    }
    
    void display(){
        Node<T> *temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    DoublyLL<int> dll;
    dll.insertNode(1,0);
    dll.insertNode(2,1);
    dll.insertNode(3,1);
    cout << dll.countNode();
    dll.display();
}