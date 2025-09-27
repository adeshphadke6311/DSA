//443. String Compression

#include <iostream>
#include <vector>
#include <string>
using namespace std;


//Time Complexity = O(n)
//Space Complexity = O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n  = chars.size(), idx = 0;
        for(int i=0; i<n; i++){
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch){
                count++; i++;
            }

            if(count == 1){
                chars[idx++] = ch;
            }else{
                chars[idx++] = ch;
                
                string str = to_string(count);
                for(char dig : str){
                    chars[idx++] = dig;
                }
            }
            
            i--;

        }

        chars.resize(idx);
        return idx;
        
    }
};

int main(){
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    Solution sol;
    int result = sol.compress(chars);

    for(int i=0; i<result; i++){
        cout<<chars[i]<<" ";
    }
    cout<<endl;
    return 0;
}