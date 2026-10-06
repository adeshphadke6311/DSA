#include <iostream>
#include <vector>
using namespace std;



class Solution {
    //Time Complexity   :   O(n*L) L - Length of Word, n = Number of Words
    //Space Complexity  :   O(L) Excluding returned answer

public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(string word : words){
            string s = word;

            for(char &c : s){
                c = tolower(c);
            }

            //Checking that which row the first character of word belongs to

            int row; 

            if(row1.find(s[0]) != string::npos){
                row = 1;
            }else if(row2.find(s[0]) != string::npos){
                row = 2;
            }else{
                row = 3;
            }

            //Checking for remaining characters
            bool valid = true;
            for(char c : s){
                if(row == 1 && row1.find(c) == string::npos){
                    valid = false;
                    break;
                }
                if(row == 2 && row2.find(c) == string::npos){
                    valid = false;
                    break;
                }
                if(row == 3 && row3.find(c) == string::npos){
                    valid = false;
                    break;
                }
            }

            if(valid){
                ans.push_back(word);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}