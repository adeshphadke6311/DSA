//3Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    //Time Complexity   :   O(n^2 + nlogn) -> O(n^2)
    //Space Complexity  :   O(uniqueTriplets)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> uniqueTriplets;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j=i+1, k = n-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                }else{
                    uniqueTriplets.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
        
                }
            }

        }

        return uniqueTriplets;
    }
};

int main(){
    vector<int> vec = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(vec);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}