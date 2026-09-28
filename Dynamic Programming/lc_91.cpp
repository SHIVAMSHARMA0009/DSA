/* decode the strings -> we are given string , return the no. of ways to decode it */

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(string &s,int i) {

    if(i == s.size()) return 1;      // we found a way to decode string
    if(s[i] == '0')  return 0;       // string with zero can't be decoded


    // at every index we have two option , include that alone character and include next character with current character

    // option 1 : include current which is a alone character
    int ways = solveUsingRecursion(s,i+1);

    // option 2 : include current and next together
    if(i+1 < s.size()) {
        int n = (s[i] - '0') * 10 + (s[i+1] - '0');
        if(n >= 10 && n <= 26) {
            ways += solveUsingRecursion(s,i+2);
        }
    }

    return ways;
} 


int solveUsingMemoisation(string &s,int i,vector<int>&dp) {

    if(i == s.size()) return 1;      // we found a way to decode string
    if(s[i] == '0')  return 0;       // string with zero can't be decoded

    if(dp[i] != -1) return dp[i];

    // at every index we have two option , include that alone character and include next character with current character

    // option 1 : include current which is a alone character
    int ways = solveUsingMemoisation(s,i+1,dp);

    // option 2 : include current and next together
    if(i+1 < s.size()) {
        int n = (s[i] - '0') * 10 + (s[i+1] - '0');
        if(n >= 10 && n <= 26) {
            ways += solveUsingMemoisation(s,i+2,dp);
        }
    }

    dp[i] = ways;

    return ways;
} 


int solveUsingTB(string &s) {

    vector<int>dp(s.size()+1,0);

    dp[s.size()] = 1;

    for(int i=s.size()-1;i>=0;i--) {

        int ways = dp[i+1];

        if(i+1 < s.size()) {
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26) {
                ways += dp[i+2];
            }
        }
        dp[i] = s[i] == '0' ? 0 : ways;
    }
    
    return dp[0];
}


int solveUsingSO(string &s) {

    int curr = 0;
    int next1 = 1;
    int next2 = 0;

    next1 = 1;

    for(int i=s.size()-1;i>=0;i--) {

        int ways = next1;

        if(i+1 < s.size()) {
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26) {
                ways += next2;
            }
        }
        curr = s[i] == '0' ? 0 : ways;
        // IMP : 
        next2 = next1;
        next1 = curr;
    }
    
    return curr;
}


int main() {
    string s;
    cout<<"Enter The String : ";
    cin>>s;

    int i = 0;
    cout<<"The No. Of Ways : "<<solveUsingRecursion(s,i)<<endl;

    vector<int>dp(s.size()+1,-1);
    cout<<"The No. Of Ways (Memoisation) : "<<solveUsingMemoisation(s,i,dp)<<endl;

    cout<<"The No. Of Ways (Tabulation) : "<<solveUsingTB(s)<<endl;

    cout<<"The No. Of Ways (SO) : "<<solveUsingSO(s)<<endl;

    return 0;
    
}
