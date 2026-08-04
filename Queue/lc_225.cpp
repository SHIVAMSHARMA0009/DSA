/* Implement stacks using queue */

#include<bits/stdc++.h>
using namespace std;

// push -> O(n)   pop : O(1)
class MyStack1 {

    queue<int>q1;        // main queue
    queue<int>q2;        // for reversal of elements

    public:
    MyStack1() {
        
    }
    
    void push(int x) {
        q2.push(x);                        // first the element into q2
        while(!q1.empty()) {               // if q1 is not empty push the elements into q2 ? this will push the all element at back of current one
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()) {
            q1.push(q2.front());         // now push all the element of q2 into q1
            q2.pop();
        }
    }
    
    int pop() {
        int pop;
        if(!q1.empty()) {
            pop = q1.front();          // current value will be popped out first
        }
        q1.pop();
        return pop;
    }
    
    int top() {
        return q1.front();              // current value will be at front
    }
    
    bool empty() {
        return q1.empty() && q2.empty();          // value of both the queues
    }

};

// using only one stack
class MyStack2 {

    queue<int>q1;

    public:
    MyStack2() {
        
    }
    
    void push(int x) {
        q1.push(x);                        // first push element into queue
        for(int i=0;i<q1.size()-1;i++){    // then reverse the queue till earlier size ? it will push the current element at front
            int element = q1.front();
            q1.pop();
            q1.push(element);
        }
    }
    
    int pop() {
       int pop = q1.front();        // pop the current value which will be at front
       q1.pop();
       return pop;
    }
    
    int top() { 
        return q1.front();        // current will be at front
    }
    
    bool empty() { 
        return q1.empty();       // value of queue
    }

};



int main() {

    MyStack1 st1;
    st1.push(10);
    st1.push(20);
    st1.push(50);
    st1.pop();
    cout<<"Top : "<<st1.top()<<endl;
    st1.pop();
    cout<<"Top : "<<st1.top()<<endl;

    MyStack2 st2;
    st2.push(110);
    st2.push(220);
    st2.push(550);
    st2.pop();
    cout<<"Top : "<<st2.top()<<endl;
    st2.pop();
    cout<<"Top : "<<st2.top()<<endl;

    return 0;
    
}