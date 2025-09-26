#include <iostream>
using namespace std;

//Time Complexity : O(n^2)
//Space Complexity : O(1)
class Solution {
public:
    string removeOccurrences(string &s, string &part) {

        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part),part.length());
        }

        return s;
    }
};

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    Solution sol;
    sol.removeOccurrences(s, part);
    cout<<s<<endl;
    return 0;
}