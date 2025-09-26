//125. Valid Palindrome
#include <iostream>
using namespace std;

//Time Complexity : O(n)
//Space Complexity  : O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;

        while(start < end){
            if(!isalnum(s[start])){
                start++;
                continue;
            } 
            if(!isalnum(s[end])){
                end--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }

            start++; end--;

        }
        return true;
        
    }
};

int main(){
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    bool result = sol.isPalindrome(s);

    if(result){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;
    }
    return 0;
}