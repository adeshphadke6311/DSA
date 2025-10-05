//78. Subsets

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



class Solution {

    //Time Complexity   :   O(2^n * n)
    //Space Complexity  :   O(2^n * n) 
public:
    void getallSubsets(vector<int> arr, vector<int>&ans, int i, vector<vector<int>>&result){

        if(i == arr.size()){
            result.push_back({ans});
            return;
        }

        //Include
        ans.push_back(arr[i]);
        getallSubsets(arr,ans,i+1, result);

        //Exclude
        ans.pop_back();
        getallSubsets(arr,ans,i+1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> result;

        getallSubsets(nums, ans, 0, result);
        return result;
        
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,3};
    vector<vector<int>> result;

    result = sol.subsets(arr);

    for(int i=0; i<pow(2,arr.size()); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}