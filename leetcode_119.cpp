//Pascals Triangle II

#include <iostream>
#include <vector>
using namespace std;


class Solution {
    //Time Complexity   :   O(n^2)
    //Space Complexity  :   O(n)
public:
    vector<int> getRow(int rowIndex) {
        

        vector<int> row;
        for(int i=0; i<=rowIndex; i++){

            row.push_back(1);

            for(int j = i-1; j>0; j--){
                row[j] = row[j] + row[j-1];
            }



        }
        return row;
        
    }
};

int main(){

    Solution sol;
    vector<int> ans = sol.getRow(3);

    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}