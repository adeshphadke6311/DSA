// 238. Product of Array Except Self

#include <iostream>
#include <vector>
using namespace std;
//Time Complexity = O(n)
//Space Complexity = O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);

        //Prefix
        for(int i=1; i<nums.size(); i++){
            ans[i]=ans[i-1]*nums[i-1];
        }

        //Suffix
        int suffix = 1;
        for(int i=nums.size()-2; i>=0; i--){
            suffix*=nums[i+1];
            ans[i]*=suffix;
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> result = {};
    Solution sol;

    result = sol.productExceptSelf(nums);

    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}