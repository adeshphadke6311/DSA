#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for(int val : nums){
            count+=freq[val]++;
        }
        return count;
        
    }
};

