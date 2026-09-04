#include <iostream>
#include <string>
using namespace std;

class Solution {
    //Time Complexity : O(d) d = Number of digits
    //Space Complexity : O(1)
  public:
    bool armstrongNumber(int n) {
        // code here
        int original = n;
        int sum = 0;
        
        int digits = to_string(n).length();
        while(n > 0){
            int lastDigit = n % 10;
            n /= 10;
            sum += pow(lastDigit, digits);
        }
        
        return original == sum;
    }
};
