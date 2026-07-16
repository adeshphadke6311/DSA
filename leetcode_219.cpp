// 219 - Contains Duplicate II

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    //Time Complexity   : O(n)
    //Space Complexity  : O(n)
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++){

            if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k){
                return true;
                
            }

            mp[nums[i]] = i;
        }
        return false;
        
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    int k = 3;
    Solution sol;
    
    if(sol.containsNearbyDuplicate(nums,k)){
        cout<<"Contains Duplicate within k distance"<<endl;
    }else{
        cout<<"Does not contain Duplicate within k distance"<<endl;
    }
    return 0;
}