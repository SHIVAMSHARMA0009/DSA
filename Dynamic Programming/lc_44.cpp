#include<bits/stdc++.h>
using namespace std;

bool solveUsingRecursion(string s,int si,string p,int pi) {

    if(si == s.size() && pi == p.size()) return true;

    if(si == s.size() && pi < p.size()) {
        while(pi < p.size()) {
            if(p[pi++] != '*') return false;
        }
        return true;
    }

    // single character matching
    if(s[si] == p[pi] || p[pi] == '?') {
        return solveUsingRecursion(s,si+1,p,pi+1);
    }

    if(p[pi] == '*') {
        // treating '*' as empty
        auto caseA = solveUsingRecursion(s,si,p,pi+1);

        //  '*' consumes one character
        auto caseB = solveUsingRecursion(s,si+1,p,pi);

        return caseA || caseB;
    }

    return false;   // char doesn't match
}



bool solveUsingMemoisation(string s,int si,string p,int pi,vector<vector<int>>& dp) {

    if(si == s.size() && pi == p.size()) return true;

    if(si == s.size() && pi < p.size()) {
        while(pi < p.size()) {
            if(p[pi++] != '*') return false;
        }
        return true;
    }

    if(dp[si][pi] != -1) return dp[si][pi];

    int ans = false;
    // single character matching
    if(s[si] == p[pi] || p[pi] == '?') {
        ans =  solveUsingMemoisation(s,si+1,p,pi+1,dp);
    }

    else if(p[pi] == '*') {
        // treating '*' as empty
        auto caseA = solveUsingMemoisation(s,si,p,pi+1,dp);

        // consuming '*' for s
        auto caseB = solveUsingMemoisation(s,si+1,p,pi,dp);

        ans =  caseA || caseB;
    }

    dp[si][pi] = ans;

    return dp[si][pi];   // char doesn't match

}



bool solveUsingTabulation(string s,string p) {

    vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
    dp[s.size()][p.size()] = true;

    // base when si == s.size() , pattern must be all '*'
    for(int pi=p.size()-1;pi>=0;pi--) {
        dp[s.size()][pi] = p[pi] == '*' && dp[s.size()][pi+1];
    }

    for(int si = s.size()-1;si>=0;si--) {
        for(int pi=p.size()-1;pi>=0;pi--) {

            int ans = false;
            // single character matching
            if(s[si] == p[pi] || p[pi] == '?') {
                ans =  dp[si+1][pi+1];
            }

            else if(p[pi] == '*') {
               // treating '*' as empty
                auto caseA = dp[si][pi+1];

               // consuming '*' for s
               auto caseB = dp[si+1][pi];
               ans =  caseA || caseB;
            }
            dp[si][pi] = ans;
        }
    }

    return dp[0][0];

}


bool solveUsingSO(string s, string p) {

    int n = s.size();
    int m = p.size();

    vector<bool> next(m + 1, false);
    vector<bool> curr(m + 1, false);

    // Base case:
    // s is exhausted and p is exhausted
    next[m] = true;

    // s is exhausted
    // Remaining pattern must contain only '*'
    for(int pi = m - 1; pi >= 0; pi--) {
        next[pi] = (p[pi] == '*') && next[pi + 1];
    }

    // Fill from bottom to top
    for(int si = n - 1; si >= 0; si--) {

        // pi == m
        // Pattern exhausted but string still has characters
        curr[m] = false;

        for(int pi = m - 1; pi >= 0; pi--) {

            // Normal character or '?'
            if(s[si] == p[pi] || p[pi] == '?') {

                curr[pi] = next[pi + 1];
            }

            // '*'
            else if(p[pi] == '*') {

                // '*' matches empty
                bool caseA = curr[pi + 1];

                // '*' matches one character
                bool caseB = next[pi];

                curr[pi] = caseA || caseB;
            }

            else {
                curr[pi] = false;
            }
        }

        // Current row becomes next row
        next = curr;
    }

    return next[0];
}


int main() {

    string s;
    cout<<"Enter The First String : ";
    cin>>s;

    string p;
    cout<<"Enter The Second String : ";
    cin>>p;

    cout<<"Are Matching ? "<<solveUsingRecursion(s,0,p,0)<<endl;


    vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
    cout<<"Are Matching (Memoisation) ? "<<solveUsingMemoisation(s,0,p,0,dp)<<endl;

    cout<<"Are Matching (Tabulation) ? "<<solveUsingTabulation(s,p)<<endl;

    cout<<"Are Matching (SO) ? "<<solveUsingSO(s,p)<<endl;

    return 0;

}