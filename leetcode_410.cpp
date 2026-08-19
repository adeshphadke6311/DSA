#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //SearchSpace S =  sum(nums) - max(nums) + 1
    //Time Complexity   :   O(n * log(S))
    //Space Complexity  :   O(1)
public:
    bool isValid(vector<int>&nums, int k, int n, long long maxSum){
        int split = 1;
        long long currSum = 0;
        for(int i=0; i<n; i++){
            if(currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }else{
                split++;
                currSum = nums[i];
            }
        }
        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long st=0, end = 0;
        long long ans = -1;
        for(int i=0; i<n; i++){
            end += nums[i];
            st = max(st, (long long) nums[i]);
        }
        
        while(st <= end){
            long long maxSum = st + (end - st)/2;

            if(isValid(nums,k,n,maxSum)){
                ans = maxSum;
                end = maxSum - 1;
            }else{
                st = maxSum + 1;
            }


        }
        return ans;
    }
};

int main(){
    return 0;
}