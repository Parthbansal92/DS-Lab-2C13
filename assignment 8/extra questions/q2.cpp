#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node*l,*r; Node(int x):v(x),l(NULL),r(NULL){}};
vector<Node*> gen(int l,int r){
    vector<Node*> res;
    if(l>r){ res.push_back(NULL); return res; }
    for(int i=l;i<=r;i++){
        vector<Node*> L=gen(l,i-1);
        vector<Node*> R=gen(i+1,r);
        for(auto a:L) for(auto b:R){
            Node*root=new Node(i);
            root->l=a; root->r=b;
            res.push_back(root);
        }
    }
    return res;
}
void serialize(Node*root, vector<int>&s){
    if(!root){ s.push_back(-1); return; }
    s.push_back(root->v);
    serialize(root->l,s);
    serialize(root->r,s);
}
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<Node*> ans=gen(1,n);
    for(auto t:ans){
        vector<int>s;
        serialize(t,s);
        for(size_t i=0;i<s.size();i++){
            if(i) cout<<" ";
            cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}
