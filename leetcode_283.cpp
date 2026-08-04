//283. Move Zeroes

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[idx++] = nums[i];
            }
        }

        while(idx < nums.size()){
            nums[idx++]  = 0;
        }


       
    }
};

int main(){
    vector<int> nums = {1,9,0,17,0,25,100};
    Solution sol;
    sol.moveZeroes(nums);

    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}