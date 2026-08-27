#include <iostream>
#include <string>
using namespace std;

class Solution {
    //Time Complexity   :   O(m * n) 
    //Space Complexity  :   O(1)
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        
        return pos != string ::npos ? pos : -1;
        
    }
};