// 26. Remove Duplicates from Sorted Array

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   = O(n)
//Space Complexity  = O(1)

class Solution{
    public:

    int removeDuplicates(vector<int>& nums){
        int l=1;
        if(nums.size()==0){
            return 0;
        }
        for(int r = 1; r < nums.size(); r++){
                if(nums[r]!=nums[r-1]){
                    nums[l]=nums[r];
                    l++;
                }
        }
        
        return l;

    }
};

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution sol;

    int k = sol.removeDuplicates(nums);
    cout<<"Number of unique elements is "<<k<<endl;
    cout<<"Unique Elements : ";
    for(int i=0; i<k; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}