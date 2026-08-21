#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n) If we include output vector, otherwise O(1)
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        //Count elements less than, equal to and greater than

        vector<int> ans(nums.size(),0);
        int less_count = 0, equal_count = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                less_count++;
                continue;
            }

            if(nums[i] == pivot){
                equal_count++;
            }
        }

        int g = less_count + equal_count;
        int e = less_count;
        int l = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < pivot){
                ans[l++] = nums[i];
            }else if(nums[i] == pivot){
                ans[e++] = nums[i];
            }else{
                ans[g++] = nums[i];
            }
        }
        
        return ans;
        
    }
};