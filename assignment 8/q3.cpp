#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* insertNode(Node* root, int x) {
    if (root == NULL) return new Node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        } else if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        } else {
            Node* t = minNode(root->right);
            root->data = t->data;
            root->right = deleteNode(root->right, t->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int a = maxDepth(root->left);
    int b = maxDepth(root->right);
    return 1 + (a > b ? a : b);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int a = minDepth(root->left);
    int b = minDepth(root->right);
    return 1 + (a < b ? a : b);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    int del;
    cin >> del;
    root = deleteNode(root, del);
    inorder(root);
    cout << endl;
    cout << "MaxDepth " << maxDepth(root) << endl;
    cout << "MinDepth " << minDepth(root) << endl;
    return 0;
}
