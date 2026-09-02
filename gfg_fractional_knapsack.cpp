#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    int val; 
    int wt;
    double ratio;
};
/* 

bool compare(Item &a, Item &b){
    return a.ratio > b.ratio;
};

*/
class Solution {
    //Time Complexity   :   O(n log n)
    //Space Compelxity  :   O(n)
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<Item>items;
        
        for(int i=0; i<val.size();i++){
            items.push_back({val[i], wt[i], (double)val[i]/wt[i]});
        }
        
        sort(items.begin(), items.end(), [](Item &a, Item &b){return a.ratio > b.ratio;});
        
        double maxVal = 0;
        for(Item &item : items){
            
            if(item.wt <= capacity){
                maxVal += item.val;
                capacity -= item.wt;
            }else{
                maxVal += item.ratio * capacity;
                break;
            }
        }
        
        
        return maxVal;
        
    }
};
