//118. Pascal's Triangle

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n^2)
    //Space Complexity  :   O(n^2)
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0; i<numRows; i++){
            vector<int> row(i+1);

            //Fill first and last element with 1

            row[0] = row[i] = 1;

            //Fill middle values

            for(int j=1; j<i; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans.push_back(row);
            
        }
        return ans;
    }
};

int main(){

    vector<vector<int>>ans;
    int numOfRows = 5;
    
    Solution Sol;

    ans = Sol.generate(numOfRows);

    for(vector<int> j : ans){
        for(int i : j){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}