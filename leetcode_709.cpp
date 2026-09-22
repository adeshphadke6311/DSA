#include <iostream>
using namespace std;

class Solution {
    //Time Complexity   :   O(n) n = Number of characters in string
    //Space Complexity  :   O(1)
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++){
            s[i] = tolower(s[i]);
        }
        return s;
        
        
    }
};