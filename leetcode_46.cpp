// 46. Permutations

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n!*n)
    //Space Complexity  :   O(n!)
public:
    void getallPermutations(vector<int>& arr, int idx, vector<int> ans, vector<vector<int>> & result){
        if(idx == arr.size()){
            result.push_back({arr});
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            swap(arr[idx], arr[i]);
            getallPermutations(arr, idx+1, ans, result);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        getallPermutations(nums,0, ans, result);
        return result;
        
    }
};

int main(){
    Solution sol;
    vector<vector<int>> result;
    vector<int> nums = {1,2,3};

    result = sol.permute(nums);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}