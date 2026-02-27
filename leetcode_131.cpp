#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    //TC = n * 2^n;
    //SC = n * 2^n;
public:
    bool isPalin(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }
    void getAllPartitions(string s, vector<string> &parts, vector<vector<string>>&ans){

        if(s.size() == 0){
            ans.push_back(parts);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string str = s.substr(0,i+1);

            if(isPalin(str)){
                parts.push_back(str);
                getAllPartitions(s.substr(i+1),parts, ans);
                parts.pop_back();

            } 
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> parts;
        vector<vector<string>> ans;
        getAllPartitions(s, parts, ans);
        return ans;
        
    }
};

int main(){
    string s = "aab";
    Solution sol;
    vector<vector<string>> ans = sol.partition(s);\

    for(vector<string> vec : ans){
        for(string s : vec){
            cout<<s<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}