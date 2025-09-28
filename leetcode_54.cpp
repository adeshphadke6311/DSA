//54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Time Complexity   :   O(m * n)
    //Space Complexity  :   O(m * n)
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, erow = m-1, scol = 0, ecol = n-1;
        vector<int> ans;
        while(srow <= erow && scol <= ecol){
            //Top
            for(int i = scol; i <= ecol; i++){
                ans.push_back(matrix[srow][i]);
            }

            //Right

            for(int i = srow+1; i <= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            //Bottom

            for(int i = ecol-1; i >= scol; i--){
                if(srow != erow){
                    ans.push_back(matrix[erow][i]);
                }
            }

            //Left

            for(int i = erow - 1; i >= srow + 1; i--){
                if(scol != ecol){
                  ans.push_back(matrix[i][scol]);
                }
            }

            srow++; erow--; scol++; ecol--;
        }

        return ans;
        
    }
};

int main(){
    vector<vector<int>> vec = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
        {13,14,15}
    };

    Solution sol;
    vector<int> result = sol.spiralOrder(vec);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}