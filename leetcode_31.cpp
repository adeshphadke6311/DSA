#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Time Complexity   :   O(n)
//Space Complexity  :   O(1)

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        //Inbuilt Function 

        /*
        next_permutation(arr.begin(), arr.end());
        */

        int pivot = -1, n = arr.size();

        for(int i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(arr.begin(), arr.end());
            return;
        }

        for(int i=n-1; i>pivot; i--){
            if(arr[i] > arr[pivot]){
                swap(arr[i], arr[pivot]);
                break;
            }
        }

        int st = pivot+1, end = n-1;

        while(st <= end){
            swap(arr[st++], arr[end--]);
        }

        // Alternate method for reversing 

        /*
        reverse(arr.begin() + pivot + 1, arr.end());
        */
 
        
        
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.nextPermutation(nums);
    
    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}