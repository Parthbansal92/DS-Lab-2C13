#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

bool isBSTUtil(Node* root, long long mn, long long mx) {
    if (!root) return true;
    if (root->data <= mn || root->data >= mx) return false;
    return isBSTUtil(root->left, mn, root->data) &&
           isBSTUtil(root->right, root->data, mx);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    if (isBST(root)) cout << "BST" << endl;
    else cout << "NotBST" << endl;
    return 0;
}
