#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
class Solution {
    //Search Space S = (1,arr[n-1] - arr[0])
    //Time Complexity   :   O(n log n + n log S)
    //Space Complexity  :   O(1)
    
    
  public:
    bool isValid(vector<int>&arr, int k, int n, int maxAllowedDist){
        int cow = 1;
        int pos = 0;
        
        for(int i=1; i<n; i++){
            if(arr[i] - arr[pos] >= maxAllowedDist){
                pos = i;
                cow++;
            }
            
            if(cow == k) return true;
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());//O(n log n)
        
        int minDist = 1;
        int maxDist = arr[n-1] - arr[0];
        
        int ans = -1;
        
        while(minDist <= maxDist){
            int maxAllowedDist = minDist + (maxDist - minDist)/2;
            
            if(isValid(arr,k,n,maxAllowedDist)){
                minDist = maxAllowedDist + 1;
                ans = maxAllowedDist;
            }else{
                maxDist = maxAllowedDist -1;
            }
        }
        
        return ans;
        
    }
};