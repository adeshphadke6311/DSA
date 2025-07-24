#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   -   O(n)
//Space Complexity  -   O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0;
        int rp=height.size()-1;
        int maxCap=0;

        while(lp<rp){
            int width = rp-lp;
            int ht = min(height[lp], height[rp]);
            int currCap = ht * width;
            maxCap = max(currCap, maxCap);

            height[lp] < height[rp] ? lp++ : rp --;

        }

        return maxCap;
        
    }
};

int main(){

    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int result = sol.maxArea(nums);
    cout<<"Maximum water that container can store is "<<result<<endl;
    return 0;
}