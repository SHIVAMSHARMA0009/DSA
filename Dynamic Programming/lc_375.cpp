/* we are given with the number n [1 -> n] , we have to guess a number between them , suppose we choose right then we won ,
   otherwise we have to pay penalty equal to number that we chooose */
/* so find we have to find minimum amount we should have to win the game */

#include<bits/stdc++.h>
using namespace std;

/* APPROACH : number choose krne par ya wo galat hoga ya shi -> aur agr galat hua toh correct no usse kam hoga ya jyada lekin utna penalty toh lag gya -> 
toh jo maximum rupay lag rha hoga dono sides me toh usse ham dono side ja sakte hai + abhi jo penalty lagi hai */

int solveUsingRecursion(int start,int end) {
    if(start >= end) {
        return 0;
    }

    int ans = INT_MAX;
    for(int i=start;i<=end;i++) {
        ans = min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
    }
    return ans;
}

int solveUsingMemoisation(int start,int end,vector<vector<int>>&dp) {
    if(start >= end) {
        return 0;
    }

    if(dp[start][end] != -1) return dp[start][end];

    int ans = INT_MAX;
    for(int i=start;i<=end;i++) {
        ans = min(ans,i+max(solveUsingMemoisation(start,i-1,dp),solveUsingMemoisation(i+1,end,dp)));
    }

    dp[start][end] = ans;

    return ans;
}


int solveUsingTabulation(int n) {

    vector<vector<int>>dp(n+2,vector<int>(n+2,0));

    for(int start=n; start>=1; start--) {
        for(int end=1; end<=n; end++) {

            if(start >= end) continue;

            int ans = INT_MAX;
            for(int i=start;i<=end;i++) {
                ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
            }
            dp[start][end] = ans;
        }
    }

    return dp[1][n];

}



int main() {

    int n;
    cout<<"Enter The Numer : ";
    cin>>n;

    cout<<"The Amount : "<<solveUsingRecursion(1,n)<<endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<"The Amount (Memoisation) : "<<solveUsingMemoisation(1,n,dp)<<endl;

    cout<<"The Amount (Tabulation) : "<<solveUsingTabulation(n)<<endl;

    return 0;

}