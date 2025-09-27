//151. Reverse words in a String

#include <iostream>
#include <algorithm>
using namespace std;

//Time Complexity = O(n)
//Space complexity = O(n)
class Solution {
public:
    string reverseWords(string &s) {

        reverse(s.begin(), s.end());   //O(n)
        int n = s.length();
        string ans = "";

        for(int i=0; i<n; i++){   //O(n)
            string word = "";
            
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            reverse(word.begin(),word.end());
            if(word.length() > 0){
                ans += " " + word;
            }
        }

        return ans.substr(1);
        
    }
};

int main(){
    string s = "  hello world  ";
    Solution sol;
    string result = sol.reverseWords(s);
    cout<<result<<endl;
    return 0;
}