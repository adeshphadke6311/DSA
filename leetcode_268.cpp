//268. Find the Missing Number

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int missingNumber(vector<int>& nums) {
        /*

        int actualSum = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            actualSum += nums[i];
        }

        int expectedSum = (size * (size+1))/2;

        int ans = expectedSum - actualSum;

        return ans;
        
        */


        //Using XOR Method
        /*
            Here, there is no problem of int overflow, because we are not using any formula
            XOR is cumulative and associative

            Cumulative 

            a ^ b = b ^ a;

            Associative 

            a ^ (b ^ c) = (a ^ b) ^ c;

        */

        //Time Complexity   :   O(n)
        //Space Complexity  :   O(1)

        int ans = nums.size();

        for(int i=0; i<nums.size(); i++){
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
        
    }
};

int main(){
    vector<int> nums = {3,0,1};
    Solution sol;
    cout<<sol.missingNumber(nums)<<endl;
    return 0;
}