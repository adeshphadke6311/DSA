//560. Subarray sum equals k

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        int count = 0;

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];

        }
        //prefixSum[j] - prefixSum[i-1] = k
        unordered_map<int,int> m;
        for(int j=0; j<n; j++){
            if(prefixSum[j] == k) count++;

            int val = prefixSum[j] - k;
            if(m.find(val) != m.end()){
                count += m[val];
            }

            if(m.find(prefixSum[j]) == m.end()){
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }
        return count;
        
    }
};

int main(){
    vector<int> vec = {1,1,1};
    int k = 2;
    Solution sol;
    cout<<"Total Count = "<<sol.subarraySum(vec,k)<<endl;
    return 0;
}