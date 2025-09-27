// 9. Palindrome Number

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while(x != 0){
            int digit = x % 10;
            
            if(revNum > (INT_MAX/10) || revNum < (INT_MIN / 10)) return 0;

            revNum = (revNum * 10) + digit;
            x /= 10;
        }

        return revNum;
        
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int revNum = reverse(x);
        return revNum == x;
        
    }
};

int main(){
    int x = -121;
    Solution sol;
    if(sol.isPalindrome(x)){
        cout<<x<<" is Palindromic Number";
    }else{
        cout<<x<<" is not a Palindromic Number";
    }
    return 0;
}