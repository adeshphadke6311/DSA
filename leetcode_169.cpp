// 169. Majority Element

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(n)
//Space Complexity  :   O(1)

class Solution{
    public:

    int count=0;
    int ans=0;
    int majorityElement(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            if(count==0){
                ans = nums[i];
            }

            if(ans==nums[i]){
                count++;
            }else{
                count--;
            }
        }

        return ans;

    }
};

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};
    Solution sol;
    int result = sol.majorityElement(nums);
    cout<<"Majority Element = "<<result<<endl;
    return 0;
}