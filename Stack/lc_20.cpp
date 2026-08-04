/* we are given the string of parentheses -> check whether the string is  valid or not */

#include<bits/stdc++.h>
using namespace std;

bool checkValidity(string &s){

    if(s.length() == 0) return true;

    stack<int>st;

    for(auto ch : s){

        if(ch == '(' || ch == '{'  || ch == '[') {             // push opening brackets
            st.push(ch);
        }
        else{
            if(!st.empty()){                          // if stack is not empty 
                char top = st.top();
                if(top == '(' && ch == ')'){          // check top of stack matches closing bracket or not -> if yes then pop it
                    st.pop();
                }
                else if (top == '{' && ch == '}'){
                    st.pop();
                }
                else if (top == '[' && ch == ']'){
                    st.pop();
                }
                else{
                    return false;               // if not -> return false
                }
            }
            else{
                return false;             // if we current char of string is closing but stack is empty -> return false
            }
        }
    }
    return st.empty();
}

int main(){

    string s;
    cout<<"Enter The String of Parentheses : ";
    getline(cin,s);

    cout<<"Is Valid ? "<<checkValidity(s);

    return 0;

}