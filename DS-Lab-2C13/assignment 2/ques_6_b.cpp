#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r,c,v;
};

vector<Node> add(vector<Node> a, vector<Node> b) {
    vector<Node> c;
    if(a[0].r!=b[0].r || a[0].c!=b[0].c) return c;
    c.push_back({a[0].r,a[0].c,0});
    int i=1,j=1;
    while(i<a.size() && j<b.size()) {
        if(a[i].r==b[j].r && a[i].c==b[j].c) {
            c.push_back({a[i].r,a[i].c,a[i].v+b[j].v});
            i++; j++;
        }
        else if(a[i].r<b[j].r || (a[i].r==b[j].r && a[i].c<b[j].c)) {
            c.push_back(a[i]);
            i++;
        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()) c.push_back(a[i++]);
    while(j<b.size()) c.push_back(b[j++]);
    c[0].v=c.size()-1;
    return c;
}

void print(vector<Node> a) {
    for(int i=0;i<a.size();i++) cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
}

int main() {
    vector<Node> A={{3,3,3},{0,0,5},{1,1,8},{2,2,6}};
    vector<Node> B={{3,3,3},{0,1,2},{1,0,3},{2,2,4}};
    vector<Node> S=add(A,B);
    print(S);
    return 0;
}
