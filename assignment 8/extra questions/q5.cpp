#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node*l,*r; Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&pre,int ps,int pe, vector<int>&in,int is,int ie, unordered_map<int,int>&pos){
    if(ps>pe||is>ie) return NULL;
    int rootv=pre[ps];
    int idx=pos[rootv];
    int leftsz=idx-is;
    Node*root=new Node(rootv);
    root->l=build(pre,ps+1,ps+leftsz,in,is,idx-1,pos);
    root->r=build(pre,ps+leftsz+1,pe,in,idx+1,ie,pos);
    return root;
}
vector<int> level(Node*root){
    vector<int>res;
    if(!root) return res;
    queue<Node*>q; q.push(root);
    while(!q.empty()){
        Node*cur=q.front(); q.pop();
        res.push_back(cur->v);
        if(cur->l) q.push(cur->l); else ;
        if(cur->r) q.push(cur->r); else ;
    }
    return res;
}
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> pre(n), in(n);
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];
    unordered_map<int,int> pos;
    for(int i=0;i<n;i++) pos[in[i]]=i;
    Node*root=build(pre,0,n-1,in,0,n-1,pos);
    vector<int> lv=level(root);
    for(size_t i=0;i<lv.size();i++){
        if(i) cout<<" ";
        cout<<lv[i];
    }
    cout<<"\n";
    return 0;
}
