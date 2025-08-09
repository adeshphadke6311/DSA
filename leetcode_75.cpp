// Sort Colors

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(n)
//Space Complexity  :   O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int mid = 0, low = 0, high = n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[low++]);
            } else if(nums[mid] == 1){
                mid++;
            } else{
                swap(nums[mid], nums[high--]);
            }
        }
        
    }
};

int main(){
    vector<int> arr = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(arr);

    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}