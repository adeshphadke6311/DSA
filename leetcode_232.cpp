#include<iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) { //O(n)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {//O(1)
        int ans = s1.top();
        s1.pop();
        return ans;

        
    }
    
    int peek() {//O(1)
        return s1.top();
    }
    
    bool empty() { //O(1)
        return s1.empty();
    }
};



int main(){
   
    
    MyQueue* obj = new MyQueue();
    obj->push(10);
    int param_3 = obj->peek();
    cout<<param_3<<endl;
    int param_2 = obj->pop();
    cout<<param_2<<endl;
    bool param_4 = obj->empty();
    if(param_4){
        cout<<"Empty"<<endl;
    }else{
        cout<<"Non-Empty\n";
    }

    return 0;
}