//90. Subsets II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Time Complexity   :   O(2^n * n);
//Space Complexity  :   O(2^n * n);

class Solution {
public:
    void getallSubsets(vector<int>& arr, vector<int>&ans, int i, vector<vector<int>> & result){
        if(i == arr.size()){
            result.push_back({ans});
            return;
        }

        //Include 
        ans.push_back(arr[i]);
        getallSubsets(arr,ans,i+1,result);

        ans.pop_back();

        //Exclude 
        int idx = i+1;
        while(idx < arr.size() && arr[idx] == arr[idx-1]){
            idx++;
        }
        getallSubsets(arr,ans,idx, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;

        getallSubsets(nums,ans,0, result);

        return result;
        
    }
};

int main(){
    vector<int> arr = {1,2,2};
    vector<vector<int>> result;
    Solution sol;

    result = sol.subsetsWithDup(arr);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}