//240. Search in a 2D Matrix II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Time Complexity   =   O(m + n)
    //Space Complexity  =   O(1)
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n-1;

        while(r < m && c >= 0){
            if(target == matrix[r][c]){
                return true;
            }else if(target < matrix[r][c]){
                c--;
            }else{
                r++;
            }
        }

        return false;
        
    }
};

int main(){
    vector<vector<int>> vec = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 50;
    Solution sol;
     
    if(sol.searchMatrix(vec,target)){
        cout<<target<<" is found"<<endl;
    }else{
        cout<<target<<" is not found"<<endl;
    }
    return 0;
}