#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
    //Time Complexity   :   O(1) amortized
    //Amortized analysis gives the average cost of operation over sequence of operations
    //Space Complexity  :   O(n)
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */