#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Node{
    T data;
    struct Node<T>* next;
};

template<class T>
class LinkedList{

private :
    Node<T>* head;

public:
    LinkedList(){
        head = NULL;
    }

    LinkedList(T value){
        head = new Node<T>();
        head->data = value;
        head->next = NULL;
    }

    T getSum(){
        Node<T> *temp = head;
        T sum = 0;
        while(temp!=NULL){
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    void insertNode(T value,int pos){
        Node<T> *t,*p=head;
        if(pos <0 || pos > countNode())
            return;
        t = new Node<T>();
        t->data=value;
        t->next=NULL;
        if(pos==0){
            t->next=head;
            head=t;
        }
        else{
            for(int i=0;i<pos-1;i++)
                p=p->next;
            t->next=p->next;
            p->next=t;
        }
    }

    T deleteNode(int idx){
        if(idx < 0 || idx >= countNode()){
            return -1;
        }
        T val;
        Node<T> *temp1,*temp2=NULL;
        if(idx==0){
            temp1 = head;
            head = head->next;
            val = temp1->data;
            delete temp1;
        }
        else{
            temp1 = head;
            for(int i=0;i<idx-1;i++){
                temp2 = temp1;
                temp1 = temp1->next;
            }

            temp2->next = temp1->next;
            val = temp1->data;
            delete temp1;
        }
        return val;
    }

    void display(){
        Node<T> *temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countNode(){
        Node<T> *temp = head;
        int cnt = 0;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
};

int main(){
    LinkedList<int> list;

    list.insertNode(5,0);
    list.insertNode(15,0);
    list.insertNode(24,1);
    list.insertNode(55,2);

    cout << "Linked List : ";
    list.display();
    cout << endl;

    list.deleteNode(0);

    cout << "Linked List : ";
    list.display();
    cout << endl;

    // int operation = -1;
    // while(operation != 5){
    //     cout << "Choose any operation from below: " << endl;
    //     cout << "1. Insert Element" << endl;
    //     cout << "2. Delete Element" << endl;
    //     cout << "3. Display List" << endl;
    //     cout << "4. Size of List" <<endl;
    //     cout << "5. Exit" << endl;

    //     cout << " Option : ";
    //     cin >> operation;

    //     if(operation==5){
    //         break;
    //     }

    //     if(operation==1){
    //         int element;
    //         int idx;
    //         cout << "Enter Index : ";
    //         cin >> idx;
    //         cout << "Enter Element : ";
    //         cin >> element;

    //         list.insertNode(element,idx);
    //     }else if(operation==2){
    //         int idx;
    //         cout << "Enter Index : ";
    //         cin >> idx;
    //         cout << "Element Removed : " << list.deleteNode(idx) << endl;
    //     }else if(operation==3){
    //         cout << "Elements : ";
    //         list.display();
    //     }else if(operation==4){
    //         cout << "Size of List : " << list.countNode() << endl;
    //     }
    // }
    return 0;
}