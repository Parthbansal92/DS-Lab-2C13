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

vector<Node> multiply(vector<Node> a, vector<Node> b) {
    vector<Node> c;
    if(a[0].c!=b[0].r) return c;
    c.push_back({a[0].r,b[0].c,0});
    vector<Node> bt=transpose(b);
    for(int i=1;i<a.size();) {
        int r=a[i].r;
        for(int j=1;j<bt.size();) {
            int col=bt[j].r;
            int sum=0;
            int ii=i,jj=j;
            while(ii<a.size() && a[ii].r==r && jj<bt.size() && bt[jj].r==col) {
                if(a[ii].c<bt[jj].c) ii++;
                else if(a[ii].c>bt[jj].c) jj++;
                else { sum+=a[ii].v*bt[jj].v; ii++; jj++; }
            }
            if(sum!=0) c.push_back({r,col,sum});
            while(jj<bt.size() && bt[jj].r==col) jj++;
            j=jj;
        }
        while(i<a.size() && a[i].r==r) i++;
    }
    c[0].v=c.size()-1;
    return c;
}

void print(vector<Node> a) {
    for(int i=0;i<a.size();i++) cout<<a[i].r<<" "<<a[i].c<<" "<<a[i].v<<endl;
}

int main() {
    vector<Node> A={{3,3,3},{0,0,5},{1,1,8},{2,2,6}};
    vector<Node> B={{3,3,3},{0,1,2},{1,0,3},{2,2,4}};
    vector<Node> M=multiply(A,B);
    print(M);
    return 0;
}
