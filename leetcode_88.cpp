//Merge Sorted Array

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(m+n)
//Space Complexity  :   O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index=m+n-1, i=m-1, j=n-1;

        if(n == 0) return;
        
        while(i >= 0 && j >= 0){
            if(nums1[i]>=nums2[j]){
                nums1[index--]=nums1[i--];
            }else{
                nums1[index--]=nums2[j--];
            }
        }

        while(j >= 0){
            nums1[index--] = nums2[j--];
        }
        
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    Solution sol;
    sol.merge(nums1,m, nums2,n);

    for(int val : nums1){
        cout<<val<<" ";
    }
    cout<<endl;
    
    return 0;
}