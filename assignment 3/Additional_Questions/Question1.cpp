/*Given an array A, find the nearest smaller element for every element A[i] in the array such that the
element has an index smaller than i.*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> Nearest_Smaller_Element(vector<int> &nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return res;
        //Time Complexity: O(N)+O(N)
        //Space Complexity: O(N)
    }
    void Display(vector<int> &nums){
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<"\t";
        }
    }
    int main(){
        vector<int>arr={2,4,3,1,8,5,9,88};

        vector<int>nse=Nearest_Smaller_Element(arr);

        Display(nse);
        return 0;
    }