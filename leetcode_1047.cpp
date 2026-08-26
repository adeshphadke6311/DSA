#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution {
    //Time Complexity   :   O(n) n = Number of Characters in String
    //Space Complexity  :   O(n)
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;
        for(char ch : s){
            if(!st.empty() && ch == st.top()){
                st.pop();
                continue;
            }
            st.push(ch);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
        

        return ans;
        
    }
};