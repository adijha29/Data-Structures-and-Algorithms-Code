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

Node* constructFromInPre(int inorder[], int preorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd)
        return nullptr;

    Node* root = new Node(preorder[preIndex++]); // Create root node from preorder array

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, root->data, inStart, inEnd); // Find index of root in inorder array

    // Constructing left subtree
    root->left = constructFromInPre(inorder, preorder, inStart, inIndex - 1, preIndex);

    // Constructing right subtree
    root->right = constructFromInPre(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    Node* root = constructFromInPre(inorder, preorder, 0, size - 1, preIndex);
    cout << "Inorder Traversal of Constructed Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
