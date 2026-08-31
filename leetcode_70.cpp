#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    /*
    //Memoization Technique : TC = O(n) SC = O(n)
    int helper(int n, vector<int>&dp){
        if(n == 1 || n == 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
        
    }
    
    */

    int climbStairs(int n) {
        if(n<=2) return n;
        
        int prev1 = 2;
        int prev2 = 1;
        
        for(int i=3; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
        
    }
};