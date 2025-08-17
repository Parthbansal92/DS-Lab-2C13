// Develop a Menu driven program to demonstrate the following operations of Arrays 
// ——MENU——- 
// 1.CREATE 
// 2. DISPLAY 
// 3. INSERT 
// 4. DELETE 
// 5. LINEAR SEARCH 
// 6. EXIT 

#include<iostream>
using namespace std;

void createArray(int a[], int n) {
    for(int i=0;i<n;i++) {
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }
}

void showArray(int a[], int n) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int addElement(int a[], int n, int pos, int val) {
    if(pos<1 || pos>n+1) {
        cout<<"Invalid position!"<<endl;
        return n;
    }
    for(int i=n-1;i>=pos-1;i--) {
        a[i+1]=a[i];
    }
    a[pos-1]=val;
    return n+1;
}

int removeElement(int a[], int n, int pos) {
    if(pos<1 || pos>n) {
        cout<<"Invalid position!"<<endl;
        return n;
    }
    for(int i=pos-1;i<n-1;i++) {
        a[i]=a[i+1];
    }
    return n-1;
}

int searchLinear(int a[], int n, int key) {
    for(int i=0;i<n;i++) {
        if(a[i]==key) return i;
    }
    return -1;
}

int insertSorted(int a[], int n, int key) {
    if(key<a[0]) return addElement(a,n,1,key);
    if(key>a[n-1]) return addElement(a,n,n+1,key);
    for(int i=0;i<n-1;i++) {
        if(a[i]<=key && key<a[i+1]) {
            return addElement(a,n,i+2,key);
        }
    }
    return n;
}

int main() {
    int arr[50], n, choice;
    cout<<"Enter size of array: ";
    cin>>n;
    createArray(arr,n);

    bool running=true;
    while(running) {
        cout<<"\nMenu:\n";
        cout<<"1. Display\n2. Insert at position\n3. Delete from position\n4. Linear Search\n5. Insert in sorted order\n6. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {
            case 1: showArray(arr,n); break;
            case 2: {
                int pos,val;
                cout<<"Enter position and value: ";
                cin>>pos>>val;
                n=addElement(arr,n,pos,val);
                showArray(arr,n);
                break;
            }
            case 3: {
                int pos;
                cout<<"Enter position to delete: ";
                cin>>pos;
                n=removeElement(arr,n,pos);
                showArray(arr,n);
                break;
            }
            case 4: {
                int key;
                cout<<"Enter value to search: ";
                cin>>key;
                int idx=searchLinear(arr,n,key);
                if(idx==-1) cout<<"Not found\n";
                else cout<<"Found at index "<<idx<<endl;
                break;
            }
            case 5: {
                int key;
                cout<<"Enter value to insert: ";
                cin>>key;
                n=insertSorted(arr,n,key);
                showArray(arr,n);
                break;
            }
            case 6: running=false; break;
            default: cout<<"Wrong choice!\n";
        }
    }
    return 0;
}
