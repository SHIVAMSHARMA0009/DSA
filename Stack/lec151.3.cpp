/* we are given an expression , just remove the redundant brackets   || e.g  (a+b) - (d)  || brackets with d are redundant */

#include <bits/stdc++.h>
using namespace std;

bool checkRedundant(string bracket)
{

    if (bracket.size() == 0)
        return false;

    stack<char> st;

    for (auto ch : bracket)
    {

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')        // push the operator & opening bracket
        {
            st.push(ch);
        }
        else if (ch == ')')                                  // if closing bracket there must one or more operator b/w ()
        {

            bool op_found = false;               // flag for operator

            while (!st.empty() && st.top() != '(')                               // pop till opening bracket found
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')              // if operator mark flag as true;
                {
                    op_found = true;
                }
                st.pop();            // pop stack element
            }

            if(!st.empty()) st.pop();      // pop the "(" opening bracket
            if(!op_found) return true;     // if no operator found -> return true;
        }
    }
    return false;               // otherwise expression in not redundant
}

int main()
{

    string brackets;
    cout << "Enter The Brackets : ";
    getline(cin, brackets);

    cout << "Does it Contain Redundant Brackets : " << checkRedundant(brackets);

    return 0;
}