//74. Search a 2D Matrix I

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Time Complexity   =   O(log(m * n))
    //Space Complexity  =   O(1)
    bool searchInRow(vector<vector<int>>& mat, int midRow, int target){
        int n = mat[0].size();
        int start = 0, end = n-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(target == mat[midRow][mid]){
                return true;
            }else if(target < mat[midRow][mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m-1;

        while(startRow <= endRow){
            int midRow = startRow + (endRow - startRow)/2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                return searchInRow(matrix, midRow, target);
            }else if(target > matrix[midRow][n-1]){
                startRow = midRow+1;
            }else{
                endRow = midRow - 1;
            }
        }
        return false;
        
    }
};


int main(){
    vector<vector<int>> vec = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 34;

    Solution sol;
    if(sol.searchMatrix(vec, target)){
        cout<<target<<" is found"<<endl;
    }else{
        cout<<target<<" is not found"<<endl;
    }
    return 0;
}