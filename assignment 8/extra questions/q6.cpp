#include <bits/stdc++.h>
using namespace std;
struct Node{int v; Node*l,*r; Node(int x):v(x),l(NULL),r(NULL){}};
Node* build(vector<int>&in,int is,int ie, vector<int>&post,int ps,int pe, unordered_map<int,int>&pos){
    if(ps>pe||is>ie) return NULL;
    int rootv=post[pe];
    int idx=pos[rootv];
    int leftsz=idx-is;
    Node*root=new Node(rootv);
    root->l=build(in,is,idx-1,post,ps,ps+leftsz-1,pos);
    root->r=build(in,idx+1,ie,post,ps+leftsz,pe-1,pos);
    return root;
}
vector<int> level(Node*root){
    vector<int>res;
    if(!root) return res;
    queue<Node*>q; q.push(root);
    while(!q.empty()){
        Node*cur=q.front(); q.pop();
        res.push_back(cur->v);
        if(cur->l) q.push(cur->l);
        if(cur->r) q.push(cur->r);
    }
    return res;
}
int main(){
    int n; if(!(cin>>n)) return 0;
    vector<int> in(n), post(n);
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>post[i];
    unordered_map<int,int> pos;
    for(int i=0;i<n;i++) pos[in[i]]=i;
    Node*root=build(in,0,n-1,post,0,n-1,pos);
    vector<int> lv=level(root);
    for(size_t i=0;i<lv.size();i++){
        if(i) cout<<" ";
        cout<<lv[i];
    }
    cout<<"\n";
    return 0;
}
