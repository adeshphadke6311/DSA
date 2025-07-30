// Binary Search
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:

    int search(vector<int>&nums, int target){
        int st = 0; 
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;  //Formula to avoid integer overflow

            if(target<nums[mid]){
                end = mid-1;

            }else if(target>nums[mid]){
                st = mid+1;
            }
            else{
                return mid;
            }

        }
        return -1;
    }
};



int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 5;

    Solution sol;
    int result = sol.search(nums, target);
    cout<<"Index of target = "<<result<<endl;
    return 0;
}