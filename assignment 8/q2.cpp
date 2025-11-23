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

Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* minNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minNode(x->right);
    Node* ans = NULL;
    while (root) {
        if (x->data < root->data) {
            ans = root;
            root = root->left;
        } else if (x->data > root->data) root = root->right;
        else break;
    }
    return ans;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maxNode(x->left);
    Node* ans = NULL;
    while (root) {
        if (x->data > root->data) {
            ans = root;
            root = root->right;
        } else if (x->data < root->data) root = root->left;
        else break;
    }
    return ans;
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
    int key;
    cin >> key;
    Node* r1 = searchRec(root, key);
    Node* r2 = searchIter(root, key);
    if (r1) cout << "FoundRec" << endl; else cout << "NotFoundRec" << endl;
    if (r2) cout << "FoundIter" << endl; else cout << "NotFoundIter" << endl;
    Node* mn = minNode(root);
    Node* mx = maxNode(root);
    if (mn) cout << "Min " << mn->data << endl;
    if (mx) cout << "Max " << mx->data << endl;
    if (r1) {
        Node* s = inorderSuccessor(root, r1);
        Node* p = inorderPredecessor(root, r1);
        if (s) cout << "Succ " << s->data << endl; else cout << "Succ None" << endl;
        if (p) cout << "Pred " << p->data << endl; else cout << "Pred None" << endl;
    }
    return 0;
}
