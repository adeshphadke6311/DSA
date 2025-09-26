//344. Reverse String
#include <iostream>
#include <vector>
using namespace std;

//Time Complexity = O(n)
//Space Complexity = O(1)


class Solution {
public:
    void reverseString(vector<char>& s) {
        int floor = 0, ceil = s.size()-1;

        while(floor < ceil){
            swap(s[floor++], s[ceil--]);
        }
        
    }
};

int main(){
    vector<char> s = {'h','e','l','l','o'}; 
    Solution sol;
    sol.reverseString(s);

    for(char ch : s){
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}