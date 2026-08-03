#include<iostream>
#include<vector>
using namespace std;
class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;

        while(idx >= 0){
            if(digits[idx] < 9){
                digits[idx]++;
                return digits;
            }else{
                digits[idx--] = 0;
            }
        }

        digits.push_back(0);
        digits[0]  = 1;
        return digits;

        
        
    }
};