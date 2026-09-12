//Number of 1 Bits

#include <iostream>
using namespace std;

class Solution {
    //Time Complexity   :   O(1)
    //Space Complexity  :   O(1)
public:
    //Brian Kernighan's Algorithm
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            n = n & (n-1);
            count+=1;
        }

        return count;
        
    }
};