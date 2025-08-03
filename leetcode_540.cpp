//Single Element in a Sorted Array

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity  :    O(log n)
//Space Complexity :    O(1)

class Solution{
    public:

    int singleElement(vector<int> & nums){
        int n = nums.size();
        int st = 0, end = n-1;

        if(n == 1) return nums[0];

        while(st <= end){
            int mid = st + (end - st)/2;

            if(mid == 0 && nums[mid] != nums[mid + 1]) return nums[mid];
            if(mid == n-1 && nums[mid] != nums[mid - 1]) return nums[mid];

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            if(mid % 2 == 0){
                if(nums[mid] == nums[mid-1]){
                    end = mid - 1;
                }else{
                    st = mid + 1;
                }
            }else{
                if(nums[mid] == nums[mid-1]){
                    st = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3,3,4,5,5};
    Solution sol;
    int result = sol.singleElement(nums);

    cout<<"Single Element in a Sorted Array : "<<result<<endl;
    return 0;
}