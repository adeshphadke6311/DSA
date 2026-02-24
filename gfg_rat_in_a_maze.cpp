#include <iostream>
#include <vector>
using namespace std;
//TC = O(4^n^2)
//SC = O(n^2) //Excluding output space
class Solution{

    public:
      void getAnswer(vector<vector<int>>& maze, int r, int c, string path, vector<string>&ans){
          //Boudary Conditions and Constraints
          int n = maze.size();
          if(r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || maze[r][c] == -1){
              return;
          }
          
          //Base Case
          if(r == n-1 && c == n-1){
              ans.push_back(path);
              return;
          }
          
          maze[r][c] = -1;
          
          getAnswer(maze, r+1,c,path + "D", ans); //Down
          getAnswer(maze,r-1,c,path+"U", ans); //Up
          getAnswer(maze,r,c-1, path+"L", ans); //Left
          getAnswer(maze,r,c+1,path+"R", ans); //Right
          
          maze[r][c] = 1;
          
      }
      vector<string> ratInMaze(vector<vector<int>>& maze) {
          // code here
          vector<string> ans;
          string path = "";
          getAnswer(maze,0,0,path,ans);
          return ans;
          
      }
  };

int main(){
    vector<vector<int>> maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};
Solution sol;

vector<string> result = sol.ratInMaze(maze);

for(string path : result){
    cout<<path<<endl;
    }
}