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
int maxd(Node*root){ if(!root) return 0; return 1+max(maxd(root->l),maxd(root->r)); }
int main(){
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        Node*root=build(a);
        cout<<maxd(root)<<"\n";
    }
    return 0;
}
