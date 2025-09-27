//204. Count Primes

#include <iostream>
#include <vector>
using namespace std;

//Time Complexity   :   O(n log n)
//Space Complexity  :   O(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        int count = 0;

        for(int i=2; i<n; i++){
            if(isPrime[i]){
                count++;
            }

            for(int j = i*2; j<n; j+=i){
                isPrime[j] = false;
            }
        }

        return count;
        
    }
};

int main(){
    int n=50;
    Solution sol;
    cout<<"Total Prime Numbers : " <<sol.countPrimes(n)<<endl;
    return 0;
}