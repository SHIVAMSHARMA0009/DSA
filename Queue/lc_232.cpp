/* we have to implement the queue using stacks */

#include<bits/stdc++.h>
using namespace std;

// method 1 : only push() operation is taking O(n)  & rest others are taking O(1)
class MyQueue1 {

    stack<int>s1;     // main  stack
    stack<int>s2;     // secondary stack
 
    public:
    MyQueue1() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){              // first put element of stack 1 into stack 2     
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);                       // then push the current element into stack 1

        while(!s2.empty()){             // now push element from stack2 to stack1  ? now current element will be at bottom of stack1
            s1.push(s2.top());         // and element inserted first will be at top
            s2.pop();
        }
    }
    
    int pop() {
        int pop = s1.top();         // acc. to queue -> element inserted first -> will move out first
        s1.pop();
        return pop;
    }
    
    int peek() {
        return s1.top();           // top element is one which was inserted first
    }
    
    bool empty() {
        return s1.empty();         // value of main stack
    }

};

// method 2 :  only push() operation is taking O(1)  & rest others are taking O(n)
class MyQueue2 {

    stack<int>s1;        // both are main stack  but stack2 is the major one
    stack<int>s2;

    public:
    MyQueue2() {
        
    }
    
    void push(int x) {                 // push element into stack1
        s1.push(x);
    }
    
    int pop() {
        int pop;
        if(!s2.empty()) {               // if stack is not empty -> its top will be very first element
            pop = s2.top();
        }
        else{
            while(!s1.empty()) {          // if empty -> then push element of s1 into s2 -> reverses -> very first which was at bottom of s1
                s2.push(s1.top());        //                                                            now will be at top of s2
                s1.pop();
            }
            pop = s2.top();
        }
        s2.pop();
        return pop;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty()) {                 // if stack is not empty -> its top will be very first element
            front = s2.top();
        }
        else{
             while(!s1.empty()) {        // if empty -> then push element of s1 into s2 -> reverses -> very first which was at bottom of s1
                s2.push(s1.top());       //                                                            now will be at top of s2
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();      // value of both the stacks
    }

};


int main() {

    MyQueue1 q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.pop();
    cout<<"Front Of Q1 : "<<q1.peek()<<endl;
    q1.pop();
    cout<<"Front Of Q1 : "<<q1.peek()<<endl;

    MyQueue2 q2;

    q2.push(110);
    q2.push(210);
    q2.push(310);
    q2.pop();
    cout<<"Front Of Q2 : "<<q2.peek()<<endl;
    q2.pop();
    cout<<"Front Of Q2 : "<<q2.peek()<<endl;

    return 0;

}