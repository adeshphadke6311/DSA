#include <iostream>
#include <stack>
#include <vector>
using namespace std;



class Solution {
    //Time Complexity   :   O(n)
    //Space Complexity  :   O(n)
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> right(n, 0);    //Right Smaller Element
        vector<int> left(n,0);      //Left Smaller Element

        stack<int> st;  

        //Right Smaller Elements Vector  O(n)

        for(int i=n-1; i>=0; i--){ 
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        //Making stack empty

        while(!st.empty()){
            st.pop();
        }


        //Left Smaller Elements Vector  O(n)

        for(int i=0; i<n; i++){    
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        

        int maxArea = 0;
        //O(n)
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            maxArea = max(currArea, maxArea);
        }

        //Calculating Rectangle area for each bar
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            heights[i] = heights[i] * width;
        }
        return maxArea;   
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;

    int ans = sol.largestRectangleArea(heights);
    for(int val : heights){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"Larget Rectangle Area = "<<ans<<endl;
    return 0;
}