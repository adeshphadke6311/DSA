#include <iostream>
using namespace std;

class Solution {
    // Time Complexity   : O(n^2)
    // find() takes O(n) and can be called multiple times.
    // erase() can also take O(n).
    
    // Space Complexity  : O(1)

public:
    string removeOccurrences(string s, string part) {
        size_t pos;

        while((pos = s.find(part)) != string :: npos){
            s.erase(pos, part.length());
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