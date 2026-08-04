/* we have to reverse the stack elements */

#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st,int &target){

    if(st.empty()){
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertAtBottom(st,target);

    st.push(topElement);

}

void reverse(stack<int>&st) {

    if(st.empty()) {
        return;
    }

    int topElement = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st,topElement);

}

int main(){

    stack<int>st;

    int n;
    cout<<"Enter Stack Size : ";
    cin>>n;

    int data;
    cout<<"Enter Stack Data : ";
    for(int i=0;i<n;i++){
        cin>>data;
        st.push(data);
    }

    reverse(st);

    cout<<"Updated Stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;

}