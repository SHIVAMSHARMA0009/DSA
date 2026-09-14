/* we are given n posts and k colours , find no of ways to paint the pillers if only two adjacent pillers are allowed to paint with same colour */

#include<bits/stdc++.h>
using namespace std;


int solveUsingRecursion(int n,int k) {

    if(n == 1) {     // if we have one pillar , then we can paint the piller with k available colors
        return k;
    }

    if(n == 2) {      // if we have two pillars then => for same k colours + for different k(k-1) colors => k + k^2 -k => k^2
        return k*k;
    }

    int ans = (solveUsingRecursion(n-1,k) + solveUsingRecursion(n-2,k))*(k-1);
    return ans;

}


int solveUsingMemoisation(int n,int k,vector<int>&dp) {

    if(n == 1) {
        return k;
    }

    if(n == 2) {
        return k*k;
    }

    if(dp[n] != -1) return dp[n];

    int ans = (solveUsingMemoisation(n-1,k,dp) + solveUsingMemoisation(n-2,k,dp))*(k-1);

    dp[n] = ans;

    return ans;

}

int solveUsingTabulation(int n,int k) {

    vector<int>dp(n+1,-1);

    dp[1] = k;
    dp[2] = k*k;

    for(int a=3; a<=n; a++) {
        int ans = (dp[a-1] + dp[a-2])*(k-1);
        dp[a] = ans;
    }

    return dp[n];

}


int solveUsingSO(int n,int k) {

    if(n == 1) return k;  
    if(n == 2) return k*k;

    int curr;
    int prev1;
    int prev2;

    prev2 = k;
    prev1 = k*k;

    for(int a=3; a<=n; a++) {
        curr = (prev1 + prev2)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;

}


int main() {

    int n;
    cout<<"Enter No. of pillars : ";
    cin>>n;

    int k;
    cout<<"Enter No. of colors : ";
    cin>>k;

    int ans = solveUsingRecursion(n,k);
    cout<<"No. of ways : "<<ans<<endl;

    vector<int>dp(n+1,-1);
    ans = solveUsingMemoisation(n,k,dp);
    cout<<"No. of ways (Memoisation) : "<<ans<<endl;

    ans = solveUsingTabulation(n,k);
    cout<<"No. of ways (Tabulation) : "<<ans<<endl;

    ans = solveUsingSO(n,k);
    cout<<"No. of ways (Space Optimization) : "<<ans<<endl;

    return 0;

}