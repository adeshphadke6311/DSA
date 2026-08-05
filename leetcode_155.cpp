//Min Stack

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    //Time Complexity   :   O(1) For each operation
    //Space Complexity  :   O(n) For pushing n values
public:
    MinStack() {
        
    }
    
    stack<long long int> st;
    long long minVal;
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minVal = value;
            return;
        }
        if(value < minVal){
                st.push((long long) 2 * value - minVal);
                minVal = value;
                return;
        }

        st.push(value);
        
    }

    
    void pop() {
        if(st.top() < minVal){
            minVal = (long long) 2 * minVal - st.top();
        }
        st.pop();
        
    }
    
    int top() {
        if(st.top() < minVal){
            return minVal;
        }
        
        return st.top();
        
    }
    
    int getMin() {
        return minVal;
        
    }
};

/* 
class MinStack {
    //Time Complexity   :   O(1) for each operation
    //Space Complexity  :   O(2*n) for n push
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }else{
            int minVal = min(value, st.top().second);
            st.push({value,minVal});
        }
        
    }
    
    void pop() {
        st.pop();
        
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
        
    }
};

 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 int main(){
    MinStack ms;
    ms.push(0);
    ms.push(-2);
    cout<<ms.getMin()<<endl;;
    ms.push(-4);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    return 0;
 }