#include <iostream>
using namespace std;

class Solution {
    //Time Complexity   :   O(1)
    //Space Complexity  :   O(1)
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return 1 + (num - 1) % 9;
        
    }
};

int main(){
    return 0;
}