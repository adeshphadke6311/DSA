#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    bool isValid(vector<int>&arr, int k, int n, int maxAllowedPages){
        int pages = 0, student = 1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > maxAllowedPages){
                return false;
            }
            if(pages + arr[i] <= maxAllowedPages){
                pages += arr[i];
            }else{
                student++;
                pages = arr[i];
            }
        }
        
        return student <= k;
    }
  
  
    int findPages(vector<int> &arr, int k) {
        // code here
        
        
        int sum = 0;
        int ans = -1;
        int n = arr.size();
        
        if(k > n){
            return -1;
        }
        
        int maxPages = 0;
        
        for(int i = 0; i < n; i++){
            sum+=arr[i];
            maxPages = max(arr[i], maxPages);
            
        }
        
        int min = maxPages, max = sum;
        
        while(min <= max){
            
            int mid = min + (max - min)/2;
            
            if(isValid(arr, k, n, mid)){
                ans = mid;
                max = mid - 1;
            }else{
                min = mid + 1;
            }
            
        }
        
        return ans;
    }
};

int main(){
    vector<int> nums = {15,17,20};
    int k = 2;
    Solution sol;
    int result = sol.findPages(nums,k);
    cout<<"Maximum Allowed Pages = "<<result<<endl;
    return 0;
}