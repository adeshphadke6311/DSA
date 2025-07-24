#include <iostream>
using namespace std;

//Time complexity = O(log n)
//Space complexity = O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long long binForm = n;
        double ans = 1;

        //Corner cases
        if(n==0) return 1.0;
        if(x==0) return 0.0;
        if(x==1) return 1.0;
        if(x==-1 && binForm%2==0) return 1.0;
        if(x==-1 && binForm%2!=0) return -1.0;



        if(n<0){
            x = 1/x;
            binForm = -(long long)n;
        }

        while(binForm>0){
            if(binForm%2==1){
                ans*=x;
            }
            x*=x;
            binForm/=2;
        }

        return ans;
        
    }
};


int main(){

    double x = 2.00000;
    int n = -2;

    Solution sol;

    double result = sol.myPow(x,n);

    cout<<"Power of x = "<<result<<endl;
    return 0;

}