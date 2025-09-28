//287. Find the Duplicate Number

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};

int main(){
    vector<int> vec = {3,1,3,4,2};
    Solution sol;
    cout<<"Duplicate Number = "<<sol.findDuplicate(vec)<<endl;
}