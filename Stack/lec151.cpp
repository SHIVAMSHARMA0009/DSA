/* Insert the top element of stack at the bottom of stack */

#include<bits/stdc++.h>
using namespace std;


void solve(stack<int>&st,int &target){

    if(st.empty()){            // if stack become empty push it to bottom
        st.push(target);
        return;
    }

    int topElement = st.top();           // store the top element every time after removal so that we can push it after empty stack
    st.pop();

    solve(st,target);                   // keep solving till stack become empty and target has been pushed to bottom

    st.push(topElement);               // then push the elements of stack after pushing our target

}

void insertAtBottom(stack<int>&st){

    if(st.empty()){
        cout<<"Empty Stack"<<endl;
        return;
    }

    int target = st.top();      // step 1 : store top element
    st.pop();                   // pop it from stack

    solve(st,target);          // then send rest of stack with target(top element) to solve in another function

}

int main(){

    stack<int> st;

    int n;
    int data;
    cout<<"Enter Stack Size : ";
    cin>>n;

    cout<<"Enter The Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        st.push(data);
    }

    insertAtBottom(st);

    cout<<"Updated Stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;

}