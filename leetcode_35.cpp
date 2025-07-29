//Search Insert Position

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity       =   O(log n)
//Space Compelxity      =   O(1)

class Solution{
    public:

    int insertPosition(vector<int>&nums, int target){
        int floor = 0;
        int ceil = nums.size()-1;
        
        while(floor<=ceil){
            int mid = (floor+ceil)/2;
            if(nums[mid]==target){
                return mid;
            }else{
                if(nums[mid]<target){
                    floor=mid+1;
                }else{
                    ceil=mid-1;
                }
            }
        }
        return floor;

    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 0;
    Solution sol;
    int result = sol.insertPosition(nums, target);

    cout<<"Insert position = "<<result<<endl;
    return 0;
}