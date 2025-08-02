//Peak Index in a Moutain Array

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(log n)
//Space Complexity  :   O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
        
    }
};

int main(){

    vector<int> nums = {0,10,5,2};
    Solution sol;

    int result = sol.peakIndexInMountainArray(nums);
    cout<<"Peak Index = "<<result<<endl;

    return 0;
}