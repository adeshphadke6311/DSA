#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int cost_i_minus2 = 0;
        int cost_i_minus1 = 0;

        for(int i=2; i<=n; i++){
            int curr = min(cost_i_minus1 + cost[i-1], cost_i_minus2 + cost[i-2]);
            cost_i_minus2 = cost_i_minus1;
            cost_i_minus1 = curr;
        }

        return cost_i_minus1;
        
    }
};