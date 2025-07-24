// 121. Best Time to Buy and Sell Stock

#include <iostream> 
#include <vector> 
using namespace std;

// Time complexity = O(n)
// Space complexity = O(1) 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];

        for(int i=1; i<prices.size(); i++){
            if(prices[i]>bestBuy){
                maxProfit = max(maxProfit, prices[i]-bestBuy);

            }
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
        
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    int result = sol.maxProfit(prices);
    cout<<"Maximum Profit = "<<result<<endl;
    return 0;
}

