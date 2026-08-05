#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int singleNumber(vector<int>& nums) {
        int singleNo = 0;

        for(int val : nums){
            singleNo ^= val;
        }

        return singleNo;
        
    }
};

int main(){
    return 0;
}