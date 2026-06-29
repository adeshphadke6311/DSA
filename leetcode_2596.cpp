#include <iostream>
#include <vector>
using namespace std;


class Solution {
    //Time Complexity   :   O(n^2)
    //Space Complexity  :   O(n^2)
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int n, int expVal){

        if(row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expVal){
            return false;
        }

        if(expVal == n * n - 1){
            return true;
        }

        if(isValid(grid, row - 2, col + 1, n, expVal + 1)) return true;
        if(isValid(grid, row - 1, col + 2, n, expVal + 1)) return true;
        if(isValid(grid, row + 1, col + 2, n, expVal + 1)) return true;
        if(isValid(grid, row + 2, col + 1, n, expVal + 1)) return true;
        if(isValid(grid, row + 2, col - 1, n, expVal + 1)) return true;
        if(isValid(grid, row + 1, col - 2, n, expVal + 1)) return true;
        if(isValid(grid, row - 1, col - 2, n, expVal + 1)) return true;
        if(isValid(grid, row - 2, col - 1, n, expVal + 1)) return true;

        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0,0, grid.size(), 0);
    }
};

int main(){

    vector<vector<int>> grid = {
    {0, 11, 16, 5, 20},
    {17, 4, 19, 10, 15},
    {12, 1, 8, 21, 6},
    {3, 18, 23, 14, 9},
    {24, 13, 2, 7, 22}
    };

    Solution sol;

    bool result = sol.checkValidGrid(grid);

    if(result){
        cout<<"Valid Grid"<<endl;

    }else{
        cout<<"Invalid"<<endl;
    }

    return 0;
}