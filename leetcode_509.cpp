//509. Fibonacci Number

#include <iostream>
using namespace std;

//Time Complexity   :   O(2^n)
//Space Complexity  :   O(n)

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }

        return fib(n-1) + fib(n-2);
        
    }
};

int main(){
    int n=4;
    Solution sol;
    cout<<"Fibonacci of "<<n<<" = "<<sol.fib(n)<<endl;
    return 0;
}