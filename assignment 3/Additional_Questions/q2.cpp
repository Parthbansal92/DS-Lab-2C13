// Design a stack that supports getMin() in O(1) time and O(1) extra space.

#include<iostream>
using namespace std;

int main(){
    int arr[8] = {5,4,3,6,7,2,1,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    stack<int> st;

    for (int i=0; i<n; i++){
        if (st.empty()){
            st.push(arr[i]);
        }
        else{
            if (arr[i]<st.top()){
                st.pop();
                st.push(arr[i]);
            }
        }
    }

    cout << st.top() << endl;
}
