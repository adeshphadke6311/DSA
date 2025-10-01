#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    //Time Complexity   :   O(n^3 + n log n) -> O(n^3)
    //Space Complexity  :   O(uniqueQuadruplets)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> uniqueQuadruplets;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = n-1;

                while(k < l){
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target){
                        k++;
                    }else if(sum > target){
                        l--;
                    }else{
                        uniqueQuadruplets.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++; l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }

                        
                    }
                }
            }
        }

        return uniqueQuadruplets;
        
    }
};

int main(){
    vector<int> vec = {1,0,-1,0,-2,2};
    int target = 0;
    Solution sol;

    vector<vector<int>> result = sol.fourSum(vec, target);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}