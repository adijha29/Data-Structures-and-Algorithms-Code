#include <iostream>
using namespace std;

// Binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int findIndex(int arr[], int value, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* constructFromInPost(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd)
        return nullptr;

    Node* root = new Node(postorder[postIndex--]); // Create root node from postorder array

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, root->data, inStart, inEnd); // Find index of root in inorder array

    // Constructing right subtree
    root->right = constructFromInPost(inorder, postorder, inIndex + 1, inEnd, postIndex);

    // Constructing left subtree
    root->left = constructFromInPost(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Function to print inorder traversal of binary tree
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = size - 1;

    Node* root = constructFromInPost(inorder, postorder, 0, size - 1, postIndex);
    cout << "Inorder Traversal of Constructed Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
