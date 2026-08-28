#include <iostream>
using namespace std;


class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int lengthOfLastWord(string s) {
        int n = s.length();

        int end = n-1;

        while(s[end] == ' '){
            end--;
        }

        int len = 0;

        while(end >= 0 && s[end] != ' '){
            len++; end--;
        }

        return len;
        
    }
};