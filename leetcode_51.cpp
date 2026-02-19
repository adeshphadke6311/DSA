#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    //TC = O(n! * n)
    //SC = O(n! * n^2)
public:
    bool isSafe(vector<string> & board, int row, int col, int n){
        //Checking for safety horizontally

        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        //Checking for safety vertically

        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //Left Diagonal

        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //Right Diagonal

        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>>&ans){
        if(row == n){
            ans.push_back({board});
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(board, row, i, n)){
                board[row][i] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n, string(n, '.'));
        nQueens(board,0,n,ans);
        return ans;


        
    }
};

int main(){
    vector<vector<string>> result;
    Solution sol;
    int n=4;
    result = sol.solveNQueens(n);

    for(int i=0; i<n; i++){
        for(string s : result[i]){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}