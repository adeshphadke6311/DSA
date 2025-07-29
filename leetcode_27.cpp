//Remove Element

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(n)
//Space Complexity  :   O(1)

class Solution{
    public:
    int removeElement(vector<int>&nums, int val){
        int pointer = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                nums[pointer]=nums[i];
                pointer++;
            }
        }
        return pointer;
    }
};

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution sol;
    int result = sol.removeElement(nums,val);
    cout<<result<<endl;
    return 0;
}