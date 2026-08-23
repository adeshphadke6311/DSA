#include <iostream>
using namespace std;

class Solution {
    //Time Complexity   :   O(m + n)
    //Space Compelxity  :   O(m + n)
public:
    
    string mergeAlternately(string word1, string word2) {
        int j = 0, k = 0;
        string ans;

        while(j < word1.length() || k < word2.length()){
            if(j < word1.length()){
                ans += word1[j++];
            }

            if(k < word2.length()){
                ans += word2[k++];
            }
        }
        return ans;
        
        
    }
};