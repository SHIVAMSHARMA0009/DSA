/* we are given the number in the stack & we have to sort the stack */

#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>&st,int &target){

    if(st.empty()){              // suppose agr stack empty -> toh stack already sorted hai usse push krdo
        st.push(target);
        return;
    }
 
    if(st.top() >= target){      // aur agr stack ka top bada hai then usse top pr push krdo
        st.push(target);
        return;
    }

    int topElement = st.top();           // nhi toh topelement ko store krlo
    st.pop();                            // aur usse hata lo

    insertSorted(st,target);             // rest of stack stack check kro

    st.push(topElement);                  // then target ko shi jagah push krne ke badd baki upper wale element push krdo
 
}

void sortStack(stack<int>&st){

    if(st.empty()){             // agr stack empty hai toh return kr jao
        return;
    }

    int target = st.top();           // ik case solve : top element ko lo aur pop krdo
    st.pop();                      

    sortStack(st);                 // baki stack ko sort

    insertSorted(st,target);       // aur ab ik sorted stack apna top element insert krdo

}

int main(){

    stack<int> st;

    int n;
    cout<<"Enter The Stack Size : ";
    cin>>n;

    int data;
    cout<<"Enter Stack Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        st.push(data);
    }

    sortStack(st);

    cout<<"Sorted stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;

}