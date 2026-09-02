#include <iostream>
#include <vector>
using namespace std;
class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        if(n == 1) return 0;
        
        int prev1 = 0;
        int prev2 = abs(height[1] - height[0]);
        
        for(int i=2; i<n; i++){
            int jump1 = prev2 + abs(height[i] - height[i-1]);
            int jump2 = prev1 + abs(height[i] - height[i-2]);
            
            int result = min(jump1, jump2);
            prev1 = prev2;
            prev2 = result;
        }
        
        return prev2;
        
        
    }
};