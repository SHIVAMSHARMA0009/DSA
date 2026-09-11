/* we are given n -> no. of dices , k -> faces over each dices (1 to k) and target , so we have to find no of way to achieve the target */

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int n,int k,int target) {

    if(target < 0) return 0;                    // target becomes -ve
    if(n == 0 && target != 0 ) return 0;         // dices are over but target remains
    if(n !=0 && target == 0) return 0;   // dices are not over but target is over
    if(n == 0 && target == 0) return 1;  // dices and target both have been consumed


    int ans = 0;
    for(int i=1;i<=k;i++) {
        ans = ans + solveUsingRecursion(n-1,k,target-i);      // why ? : n-1 -> used one dice value , target - i -> the value that has been used from dice
    }

    return ans;
}

long long int mod = 1000000007;

int solveUsingMemoisation(int n,int k,int target,vector<vector<long long int>>&dp) {

    if(target < 0) return 0;                   
    if(n == 0 && target != 0 ) return 0;         
    if(n !=0 && target == 0) return 0;   
    if(n == 0 && target == 0) return 1;  

    if(dp[n][target] != -1) return dp[n][target];    // step 3 : if exist return it  

    int ans = 0;
    for(int i=1;i<=k;i++) {
        ans = (ans%mod + solveUsingMemoisation(n-1,k,target-i,dp)%mod)%mod;      
    }

    dp[n][target] = ans;   // step 2 : store the ans

    return ans;
}

int solveUsingTabulation(int n,int k,int target) {

    vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));   // create dp

    dp[0][0] = 1;   // analyse base case

    for(int a=1;a<=n;a++) {
        for(int t=1;t<=target;t++) {   // reverse flow and take care of looping variables
            int ans = 0;
            for(int i=1;i<=k;i++) {

                long long int temp = 0;
                if(t-i >= 0) temp =  dp[a-1][t-i]%mod;

                ans = (ans%mod + temp)%mod;      
            }
            dp[a][t] = ans;  
        }
    }

    return dp[n][target];
}

int solveUsingSO(int n,int k,int target) {

    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);

    prev[0] = 0;     // dp[0] = 0th wali row


    for(int a=1;a<=n;a++) {
        for(int t=1;t<=target;t++) {   // reverse flow and take care of looping variables
            int ans = 0;
            for(int i=1;i<=k;i++) {

                long long int temp = 0;
                if(t-i >= 0) temp =  prev[t-i]%mod;

                ans = (ans%mod + temp)%mod;      
            }
            curr[t] = ans;  
        }
        prev = curr; // shifting
    }

    return prev[target];
}

int main() {

    int n;
    cout<<"Enter No. of dices : ";
    cin>>n;

    int k;
    cout<<"Enter Face Value : ";
    cin>>k;

    int target;
    cout<<"Enter The target : ";
    cin>>target;

    // int ans = solveUsingRecursion(n,k,target);
    // cout<<"The Number of Ways : "<<ans<<endl;

    // n , target both the parameters are changing => n as rows and target as columns

    vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));       // step 1 : find dp , create it , initialize it and pass it
    int ans = solveUsingMemoisation(n,k,target,dp);
    cout<<"The Number of Ways (Momoisation) : "<<ans<<endl;

    ans = solveUsingTabulation(n,k,target);
    cout<<"The Number of Ways (Tabulation)   : "<<ans<<endl;

    return 0;

}