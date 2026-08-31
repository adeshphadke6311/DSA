#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    // Time Complexity  :   O(n)
    // Space Complexity :   O(n)
    int helper(vector<int>& nums, int n, vector<int> &dp){
        if(n == 0) return nums[0];
        if(n == 1){
            return max(nums[0], nums[1]);
        }
        
        if(dp[n] != -1) return dp[n];
        

        return dp[n] = max(helper(nums, n-1,dp), helper(nums, n-2, dp) + nums[n]);


    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        
        vector<int> dp (n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        return helper(nums, n-1,dp);
        
    }
    
    */

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
       

        for(int i=2; i<n; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;


    }
};