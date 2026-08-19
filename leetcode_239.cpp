#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<k; i++){ //O(k)
            //Elimination on non-viable answer
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            // Each index is pushed and popped at most once.
            // Therefore, across the entire loop, total pop operations are O(k).
            dq.push_back(i);
        }

        for(int i=k; i<n; i++){ //O(n-k)
            ans.push_back(nums[dq.front()]);

            //Elimination of non-window elements i.e i-k
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            //Elimination of non-viable
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            // Across all iterations, each index can be popped at most once.
            // Therefore, total pop operations are O(n-k), not O((n-k)^2).

            dq.push_back(i);

        }

        //For Storing max of last window
        ans.push_back(nums[dq.front()]);
        return ans;


        
    }
};

int main(){
    return 0;
}