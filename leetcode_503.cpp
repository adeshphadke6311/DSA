#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i%n]){
                st.pop();
            }

            ans[i%n] = st.empty() ? -1 : nums[st.top()];
            st.push(i%n);
        }
        return ans;
        
        /*
        //Time Complexity   :   O(n^2)
        //Space Complexity  :   O(n)
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0; i<n; i++){
            bool isFound = false;
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    isFound = true;
                    break;
                }

            }
            
            if(isFound) continue;

            for(int j=0; j<i; j++){
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    break;
                }
            }
        }

        return ans;

        */
    }
};
int main(){
    vector<int> nums = {1,2,1};
    Solution sol;
    vector<int> ans = sol.nextGreaterElements(nums);

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}