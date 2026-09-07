#include <iostream>
using namespace std;
class Solution {
    //Time Complexity   :   O(1)
    //Space Complexity  :   O(1)
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        return (n & (n-1)) == 0;
        
    }
};