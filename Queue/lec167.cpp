/* first non-repeating character in s stream */

#include<bits/stdc++.h>
using namespace std;

// T.C : O(n)    ||    S.C : O(n)     ||
void find_non_Repeating(string s) {

    if(s.empty() || s.size() == 1) {
        cout<<s<<endl;
        return;
    }
    
    vector<int> freq(26,0);
    queue<char>q;
    
    for(auto ch : s) {

        freq[ch-'a']++;                  // for non-repeating , count frequency
        q.push(ch);                      // to first -> use queue as front will return first element

        while(!q.empty()) {
            if(freq[q.front() - 'a'] > 1) {       // if element at front with freq is greater than 1 then pop it from front
                q.pop();
            }
            else{
                cout<<q.front()<<" ";            // otherwise print it ONCE
                break;
            }
        }

        if(q.empty()) {                      // suppose popping -> queue is empty -> all previous elements were repeating -> then print "#"
        cout<<"#"<<" ";
        }

    }

}

int main () {
     
    string s;
    cout<<"Enter The string : ";
    getline(cin,s);

    find_non_Repeating(s);

    return 0;
}