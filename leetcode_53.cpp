#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Time Complexity    -   O(n)
//Space Complexity   -   O(1)

class Solution{
    public:

    int maxSubarraySum(vector<int>&nums){
        int currSum = 0;
        int maxSum = INT_MIN;
        for(int i : nums){
            currSum+=i;
            maxSum = max(currSum, maxSum);

            if(currSum<0){
                currSum = 0;
            }


        }
        return maxSum;
    }
};

int main(){

    vector<int> numbers = {-2,1,-3,4,-1,2,1,-5,4};

    Solution sol;
    int result = sol.maxSubarraySum(numbers);
    cout<<"Maximum subarray sum = "<<result<<endl;

    return 0;
}