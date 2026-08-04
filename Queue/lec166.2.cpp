/* given a queue with interger k , reverse the first k elements of queue */

#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q,int k) {
    
    if(q.empty()) {
        cout<<"Empty Queue !!"<<endl;
        return;
    }

    int n = q.size();

    if(k > n || k <= 0 ) return;

    // step 1 : push first k element into stack
    stack<int>st;
    int i=0;
    while(i < k) {
        int element = q.front();
        q.pop();
        i++;
        st.push(element);
    }

    // step 2 : push back to queue
    while(!st.empty()) {
        int element = st.top();
        st.pop();
        q.push(element);
    }

    // step 3 : now pop n - k element from  the queue & push it back to the queue
    i = 0;
    while(i < n - k) {
        int element = q.front();
        q.pop();
        i++;
        q.push(element);
    }

}

int main() {

    int n;
    cout<<"Enter No. of  element of queue : ";
    cin>>n;

    queue<int>q;
    int data;
    cout<<"Enter queue value : ";
    for(int i=0;i<n;i++) {
        cin>>data;
        q.push(data);
    }

    int k;
    cout<<"Enter Value for k : ";
    cin>>k;

    reverse(q,k);

    cout<<"After Updating : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;

}