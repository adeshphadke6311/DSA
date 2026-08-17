#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
    public :

    int findCelebrity(vector<vector<int>> &matrix){

         int n= matrix.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            st.push(i);
        }

        while(st.size() > 1){
            int i = st.top();
            st.pop();

            int j = st.top();
            st.pop();

            if(matrix[i][j]){
                st.push(j);

            }else{
                st.push(i);
            }
        }

        int celeb = st.top();

        for(int i=0; i<n; i++){
            if(i == celeb) continue;
            if(!matrix[i][celeb] || matrix[celeb][i]){
                return -1;
            }
        }

        return celeb;
    }

    

    
};

int main(){
    vector<vector<int>> matrix = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    Solution sol;
    
    cout<<sol.findCelebrity(matrix)<<endl;
    return 0;
}