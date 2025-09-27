//567. Permutation in String

#include <iostream>
using namespace std;

//Time Complexity = O(|s1| * |s2|)
//Space Complexity = O(1)
class Solution {
public:

    //TC = O(1)
    bool isFreqSame(int freq1[26], int freq2[26]){
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    //TC = O(n^2)
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        
        for(int i=0; i<s1.length(); i++){
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();

        for(int i=0; i<s2.length(); i++){
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < s2.length()){
                windFreq[s2[idx] - 'a']++;
                windIdx++,idx++;
            }

            if(isFreqSame(freq, windFreq)){
                return true;
            }


        }

        return false;
        
    }
};

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    Solution sol;
    bool result = sol.checkInclusion(s1,s2);

    if(result){
        cout<<"Found permutation in s2"<<endl;
    }else{
        cout<<"Not found";
    }
    return 0;
}