//Summary Ranges

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        int i=0;
        while(i<n){
            int start = nums[i];


            //Check for consecutive sequence
            while(i+1<n && nums[i+1] == nums[i] + 1){
                i++;
            }

            int end = nums[i];

            if(start == end){
                ans.push_back(to_string(start));
            }else{
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
            i++;
        }
        return ans;

    }
};

int main(){

    Solution sol;
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> result = sol.summaryRanges(nums);

    for(string ans : result){
        cout<<ans<<" , ";
    }
    cout<<endl;
    return 0;
}