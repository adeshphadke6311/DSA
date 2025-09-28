//. Two Sum 

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;

        for(int i=0; i<n; i++){
            int first = nums[i];
            int second = target - first;

            if(m.find(second) != m.end()){
                return {m[second],i};
            }

            m[first] = i;
        }

        return {};
        
    }
};

int main(){
    vector<int> vec = {3,2,4};
    int target = 6;
    vector<int> ans;
    Solution sol;
    ans = sol.twoSum(vec,target);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
}