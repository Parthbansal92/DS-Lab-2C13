#include <bits/stdc++.h>
using namespace std;

struct Node {
    int r,c,v;
};

vector<Node> transpose(vector<Node> a) {
    vector<Node> b;
    b.push_back({a[0].c,a[0].r,a[0].v});
    for(int i=1;i<a.size();i++) {
        b.push_back({a[i].c,a[i].r,a[i].v});
    }
    sort(b.begin()+1,b.end(),[](Node &x,Node &y){
        if(x.r==y.r) return x.c<y.c;
        return x.r<y.r;
    });
    return b;
}

void print(vector<Node> a) {
    for(int i=0;i<a.size();i++) cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
}

int main() {
    vector<Node> A={{3,3,3},{0,0,5},{1,1,8},{2,2,6}};
    vector<Node> T=transpose(A);
    print(T);
    return 0;
}
