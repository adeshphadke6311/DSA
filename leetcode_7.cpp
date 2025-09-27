// 7. Reverse Integer

#include <iostream>
#include <climits>
using namespace std;

//Time Complexity   :   O(log10(n))
//Space Complexity  :   O(1)

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
};

int main(){
    int x = -123;
    Solution sol;
    cout<<sol.reverse(x)<<endl;
    return 0;
}