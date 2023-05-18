#include <iostream>
#include <string>
using namespace std;

// Binary Search Tree Node
class Node {
public:
    string name;
    long long int phoneNumber;
    Node* left;
    Node* right;
    Node(const string& name, long long int phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        left = right = nullptr;
    }
};

Node* insert(Node* root, const string& name, long long int phoneNumber) {
    if (root == nullptr) {
        return new Node(name, phoneNumber);
    }

    if (name < root->name) {
        root->left = insert(root->left, name, phoneNumber);
    }
    else if (name > root->name) {
        root->right = insert(root->right, name, phoneNumber);
    }
    return root;
}

Node* search(Node* root, const string& name) {
    if (root == nullptr || root->name == name) {
        return root;
    }

    if (name < root->name) {
        return search(root->left, name);
    }
    else {
        return search(root->right, name);
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << "Name: " << root->name << ", Phone Number: " << root->phoneNumber << endl;
    inorderTraversal(root->right);
}

int main() {
    // Initialization of Phone Book BST
    Node* phoneBook = nullptr;

    // Inserting some contacts
    phoneBook = insert(phoneBook, "Dhruv", 1234567890);
    phoneBook = insert(phoneBook, "Manav", 9876543210);
    phoneBook = insert(phoneBook, "Choksi", 4567890123);
    phoneBook = insert(phoneBook, "Gaurav", 7890123456);
    phoneBook = insert(phoneBook, "Avi", 2345678901);

    cout << "\n\n";
    
    // Search for a contact in the phone book
    Node* contact = search(phoneBook, "Manav");
    if (contact != nullptr) {
        cout << "Contact found: Name: " << contact->name << ", Phone Number: " << contact->phoneNumber << endl;
    } else {
        cout << "Contact not found!!!" << endl;
    }

    cout << "\n\n";

    // Dictionary Traversal
    cout << "Phone Book Dictionary:" << endl;
    inorderTraversal(phoneBook);

    return 0;
}
