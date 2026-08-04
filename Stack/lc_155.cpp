/* we have to perform the push() , pop() , top() , getmin() operation over stack in O(1) time complexity */

/*  we can do push(),pop() & top() in O(1) but think about getmin() */

#include<iostream>
#include<vector>
using namespace std;

class MinStack {

    vector<pair<int,int>>st;     // using vector with pair -> first will contain element & second will contain the minimum value

    public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            pair<int,int>p;
            p.first = value;
            p.second = value;
            st.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first = value;
            p.second = min(value,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

int main() {

    MinStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"Top : "<<st.top()<<endl;
    cout<<"Min : "<<st.getMin()<<endl;

    st.pop();
    cout<<"Top : "<<st.top()<<endl;
    cout<<"Min : "<<st.getMin()<<endl;

    return 0;

}