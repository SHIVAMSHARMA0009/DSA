/* we are given coins and amount , count the minimum number of coins required to make up the amount */

#include<bits/stdc++.h>
using namespace std;


int solveUsingRecursion(vector<int>&nums,int amount) {

    if(amount == 0) return 0;

    int mini = INT_MAX;

    for(int i=0;i<nums.size();i++) {
        if(nums[i] <= amount) {
            int curr_count = solveUsingRecursion(nums,amount - nums[i]);
            if(curr_count != INT_MAX) {
                mini = min(mini,1 + curr_count);
            }
        }
    }
    return mini;
}


int solveUsingMemoisation(vector<int>&nums,int amount,vector<int>&dp) {

    if(amount == 0) return 0; 

    if(dp[amount] != -1) return dp[amount];     // step 3 : if ans exist return it

    int mini = INT_MAX;

    for(int i=0;i<nums.size();i++) {
        if(nums[i] <= amount) {
            int curr_count = solveUsingMemoisation(nums,amount - nums[i],dp);
            if(curr_count != INT_MAX) {
                mini = min(mini,1 + curr_count);
            }
        }
    }

    dp[amount] = mini;   // step 2 : store the ans
    
    return dp[amount];
}


int solveUsingTabulation(vector<int>&nums,int amount) {

    vector<int>dp(amount+1,INT_MAX);     // step 1 : create dp , initialize it

    dp[0] = 0;                       // step 2 : analyze base case

    for(int val=1;val<=amount;val++) {

        int mini = INT_MAX;                   // step 3 : reverse flow

        for(int i=0;i<nums.size();i++) {
            if(nums[i] <= val) {
                int curr_count = dp[val - nums[i]];
                if(curr_count != INT_MAX) {
                    mini = min(mini,1 + curr_count);
                }
            }
        }
        dp[val] = mini;
    }

    return dp[amount];     // return ans
}


int main() {

    int n;
    cout<<"Enter No. of Coins : ";
    cin>>n;

    vector<int>coins(n);
    cout<<"Enter Coin's Value : ";
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }

    int amount;
    cout<<"Enter Amount : ";
    cin>>amount;

    int ans = solveUsingRecursion(coins,amount);
    ans = ans != INT_MAX ? ans : -1;
    cout<<"The Minimum coin count : "<<ans<<endl;

    vector<int>dp(amount+1,-1);             //step 1 : find dp array , create it , initialize it and pass it
    ans = solveUsingMemoisation(coins,amount,dp);
    ans = ans != INT_MAX ? ans : -1;
    cout<<"The Minimum coin count (Memoisation) : "<<ans<<endl;

    ans = solveUsingTabulation(coins,amount);
    ans = ans != INT_MIN ? ans : -1;
    cout<<"The Minimum coin count (Bottom-Up) : "<<ans<<endl;

    return 0;

}