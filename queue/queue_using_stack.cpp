#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        
        if(s1.empty() && s2.empty())
            return -1;
        else if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int topVal = s2.top();
        s2.pop();
       return topVal; 
    }
    
    int peek() {
        if(!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

        }
        int topVal = s2.top();
        return topVal;
    }
    
    bool empty() {
        
        if(s1.empty() && s2.empty())
            return true;
        
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */