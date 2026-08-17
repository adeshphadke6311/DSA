#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(1)
public:
    int trap(vector<int>& height) {

        //Optimal Approach

        int n = height.size();
        int l=0, r=n-1; 
        int lmax = 0, rmax = 0;
        int trappedWater = 0;
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                trappedWater += lmax - height[l];
                l++;
            }else{
                trappedWater += rmax - height[r];
                r--;
            }
        }
        return trappedWater;

        /*
        //Better Approach

        //Time Complexity   :   O(n)
        //Space Complexity  :   O(n)
        int n = height.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0] = height[0]; rmax[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1], height[i]);
        }

        for(int i=n-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], height[i]);
        }

        int trappedWater = 0;

        for(int i=0; i<n; i++){
            trappedWater += min(lmax[i], rmax[i]) - height[i];
        }
        return trappedWater;
        /*

        //Naive Method

        //Time Complexity   :   O(n^2)
        //Space Complexity  :   O(1)
        int trappedWater = 0;
        int n = height.size();

        for(int i=0; i<n; i++){
            int lmax = i, rmax = i;

            for(int j=0; j<i; j++){
                if(height[j] > height[lmax]){
                    lmax = j;
                }
            }

            for(int j=i+1; j<n; j++){
                if(height[j] > height[rmax]){
                    rmax = j;
                }
            }

            int barHold = min(height[lmax], height[rmax]) - height[i];
            trappedWater += barHold;

        }
        return trappedWater;
        */
    }
};


int main(){
    vector<int> height = {4,2,0,3,2,5};
    Solution sol;
    cout<<"Trapped Rainwater = "<<sol.trap(height)<<endl;
    return 0;
}