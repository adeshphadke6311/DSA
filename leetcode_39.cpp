#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
    //TC = O(3^(T / min(candidates)) × logK × L)
    //SC = O(T / m) + O(K × L)
public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& candidates, int idx, vector<int>& combination, vector<vector<int>>& ans, int target){
        if(idx == candidates.size() || target < 0){
            return;
        }


        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back({combination});
                s.insert(combination);
            }
            return;
            
        }

        combination.push_back(candidates[idx]);
        //Single time inclusion
        getAllCombinations(candidates,idx+1, combination, ans, target - candidates[idx]);

        //Multiple time inclusion
        getAllCombinations(candidates, idx, combination, ans, target - candidates[idx]);

        //Exclusion
        combination.pop_back();
        getAllCombinations(candidates, idx+1, combination, ans, target);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllCombinations(candidates,0,combination, ans, target);
        return ans;
        
    }
};

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>>result;
    Solution sol;
    result = sol.combinationSum(candidates, target);

    for(vector<int> vec : result){
        for(int val : vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;

}