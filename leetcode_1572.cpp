#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n) n = Number of Rows or Columns in matrix
    //Space Complexity  :   O(1)
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for(int i=0; i<n; i++){
            sum += mat[i][i];

            if(i != n-i-1){
                sum += mat[i][n-i-1];
            }
        }
        return sum;
        
    }
};