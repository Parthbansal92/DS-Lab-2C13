#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node*l,*r; Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&a){
    if(a.empty()||a[0]==-1) return NULL;
    vector<Node*> nodes(a.size(),NULL);
    for(size_t i=0;i<a.size();i++) if(a[i]!=-1) nodes[i]=new Node(a[i]);
    for(size_t i=0;i<a.size();i++) if(nodes[i]){
        size_t l=2*i+1,r=2*i+2;
        if(l<a.size()) nodes[i]->l=nodes[l];
        if(r<a.size()) nodes[i]->r=nodes[r];
    }
    return nodes[0];
}
vector<int> rightView(Node*root){
    vector<int>res;
    if(!root) return res;
    queue<Node*>q; q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            Node*cur=q.front(); q.pop();
            if(i==s-1) res.push_back(cur->v);
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
        }
    }
    return res;
}
int main(){
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        Node*root=build(a);
        vector<int>rv=rightView(root);
        for(size_t i=0;i<rv.size();i++){
            if(i) cout<<" ";
            cout<<rv[i];
        }
        cout<<"\n";
    }
    return 0;
}
