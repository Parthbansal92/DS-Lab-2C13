#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node*l,*r; Node(int x):v(x),l(NULL),r(NULL){}};
int sumLeft(Node*root,bool isLeft){
    if(!root) return 0;
    if(!root->l && !root->r) return isLeft?root->v:0;
    return sumLeft(root->l,true)+sumLeft(root->r,false);
}
Node* buildFromLevel(vector<int>&a){
    if(a.empty()||a[0]==-1) return NULL;
    vector<Node*> nodes(a.size(),NULL);
    for(size_t i=0;i<a.size();i++) if(a[i]!=-1) nodes[i]=new Node(a[i]);
    for(size_t i=0;i<a.size();i++) if(nodes[i]){
        size_t l=2*i+1, r=2*i+2;
        if(l<a.size()) nodes[i]->l = nodes[l];
        if(r<a.size()) nodes[i]->r = nodes[r];
    }
    return nodes[0];
}
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Node*root=buildFromLevel(a);
    cout<<sumLeft(root,false)<<"\n";
    return 0;
}
