/* we are given queue , we have to reverse it */

#include<bits/stdc++.h>
using namespace std;

// approach 1 : stack approach    ||    T.C : O(n)      ||    S.C : O(n)    ||
void reverse(queue<int>&q) {

    if(q.empty()) {
        cout<<"Queue is empty !!";
        return;
    }

    // step 1 : push element into stack
    stack<int>st;
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        st.push(element);
    }

    // step  2 : push element back to queue
    while(!st.empty()) {
        int element = st.top();
        st.pop();
        q.push(element);
    }

} 

// approach 2 : recursion    ||   T.C : O(n)     ||   S.C : O(n)    ||
void recurse(queue<int>&q) {

    if(q.empty()) {
        return;
    }

    int element = q.front();
    q.pop();

    recurse(q);

    q.push(element);

}

int main() {

    int n;
    cout<<"Enter No. of element is queue : ";
    cin>>n;

    queue<int> q;
    int data;
    cout<<"Enter Queue Data : "<<endl;
    for(int i=0;i<n;i++) {
        cin>>data;
        q.push(data);
    }

    recurse(q);

    cout<<"After Reversing : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}