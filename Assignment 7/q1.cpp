#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a) {
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[idx]) idx=j;
        }
        swap(a[i],a[idx]);
    }
}

void insertionSort(vector<int> &a) {
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(vector<int> &a) {
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int sw=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                sw=1;
            }
        }
        if(!sw) break;
    }
}

void mergeArr(vector<int> &a,int l,int m,int r){
    vector<int>x,y;
    for(int i=l;i<=m;i++) x.push_back(a[i]);
    for(int i=m+1;i<=r;i++) y.push_back(a[i]);
    int i=0,j=0,k=l;
    while(i<x.size() && j<y.size()){
        if(x[i]<=y[j]) a[k++]=x[i++];
        else a[k++]=y[j++];
    }
    while(i<x.size()) a[k++]=x[i++];
    while(j<y.size()) a[k++]=y[j++];
}

void mergeSort(vector<int> &a,int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    mergeArr(a,l,m,r);
}

int partitionArr(vector<int> &a,int l,int r){
    int p=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<=p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(vector<int> &a,int l,int r){
    if(l>=r) return;
    int pi=partitionArr(a,l,r);
    quickSort(a,l,pi-1);
    quickSort(a,pi+1,r);
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int ch;
    cin>>ch;

    if(ch==1) selectionSort(a);
    else if(ch==2) insertionSort(a);
    else if(ch==3) bubbleSort(a);
    else if(ch==4) mergeSort(a,0,n-1);
    else if(ch==5) quickSort(a,0,n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
