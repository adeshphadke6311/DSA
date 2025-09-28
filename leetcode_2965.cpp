//2965. Find Missing and Repeated Values

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    //Time Complexity   :   O(n^2);
    //Space Complexity  :   O(n^2);
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        vector<int> ans;
        int a = 0, b = 0;

        int expectedSum = n*n * (n*n + 1)/2;
        int actualSum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);

                actualSum += grid[i][j];
            }
        }

        // actualSum = expectedSum + a - b

        b = expectedSum - actualSum + a;
        ans.push_back(b);
        return ans;
        
    }
};

int main(){
    vector<vector<int>> vec = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans;
    Solution sol;
    ans = sol.findMissingAndRepeatedValues(vec);

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}