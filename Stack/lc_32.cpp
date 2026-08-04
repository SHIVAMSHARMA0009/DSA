/* we are expression of strings , return the length of longest valid parenthesis */

#include<bits/stdc++.h>
using namespace std;

int longestValid(string s) { 

    stack<int> st;
    st.push(-1);     // we will push -1 in starting because eg. ()()  ans = 3 - (-1) = 4

    int max_len = 0;

    for(int i=0;i<s.size();i++) {
        if (s[i] == '(') {              // will push the index of opening bracket
            st.push(i);
        }
        else{
            st.pop();                    // will pop the top for closing bracket
            if(!st.empty()) {
                max_len = max(max_len,i - st.top());    // after pop if index is not empty then calculate max_length
            } 
            else {
                st.push(i);         // if after pop , stack is empty -> push current index
            }
        }
    }

    return max_len;
}

int main() {

    string s;
    cout<<"Enter The Expression : ";
    getline(cin,s);

    cout<<"Length Of Longest Valid Parentheses : "<<longestValid(s);

    return 0;
}