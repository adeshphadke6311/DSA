#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char,int> m;

        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()){
                q.push(i);
            }
            m[s[i]]++;

            while(!q.empty() && m[s[q.front()]] > 1){
                q.pop();
            }
        }


        return q.empty() ? -1 : q.front();
        
    }
};