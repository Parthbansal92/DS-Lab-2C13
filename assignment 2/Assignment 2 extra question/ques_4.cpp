// 4) Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
// Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e.,
// put all 0s first, then all 1s and all 2s in last.
#include <iostream>
#include <vector>
using namespace std;

void arrange(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, m = 0, h = n - 1;

    while(m <= h)
    {
        if(nums[m] == 0)
        {
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if(nums[m] == 1)
        {
            m++;
        }
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 1, 0, 1, 2, 0, 0};
    arrange(nums);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}
