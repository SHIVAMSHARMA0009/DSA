/* we are given queue -> Interleave its first & second half of queue */

/* e.g : [10 20 30 40][50 60 70 80]  => 10 50 20 60 30 70 40 80 */

#include<bits/stdc++.h>
using namespace std;

void interLeave(queue<int>&q) {

    if(q.empty() || q.size() == 1 || q.size() == 2) return;

    queue<int>q1;
    queue<int>q2;

    int size = q.size();
    int k = 0;
    while(k < size/2) {                   // store the half values in first queue
        int element = q.front();
        q.pop();
        q1.push(element);
        k++;
    }
  
    while(!q.empty()) {                  // rest half in another queue
        int element = q.front();
        q.pop();
        q2.push(element);
    }

    while(!q1.empty() || !q2.empty()) {          // then push

        if(!q1.empty()){       
            int element = q1.front();           // element from first queue
            q1.pop();
            q.push(element);
        }

        if(!q2.empty()){
            int element = q2.front();          // element from second queue
            q2.pop();
            q.push(element);
        }

    }

}

int main () {

    int n;
    cout<<"Enter no. of element of queue : ";
    cin>>n;

    int data;
    queue<int>q;
    cout<<"Enter Queue Value : ";
    for(int i=0;i<n;i++) {
        cin>>data;
        q.push(data);
    }

    interLeave(q);

    cout<<"After InterLeave : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;

}