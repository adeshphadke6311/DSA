#include<iostream>
#include<stack>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.size() == 0) return false; //More number of closings
                if(
                    (st.top() == '(' && s[i] == ')') || 
                    (st.top() == '{' && s[i] == '}') || 
                    (st.top() == '[' && s[i] == ']')
                    ){
                        st.pop();
                }else{
                    return false;
                }
                
            }
        }

        return st.size() == 0; //More number of Openings
        
    }
};

int main(){
    string s = "([])";
    Solution sol;
    bool result = sol.isValid(s);
    if(result){
        cout<<"Valid String"<<endl;
    }else{
        cout<<"Invalid String"<<endl;
    }
}