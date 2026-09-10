/* we are given an array , return the length of longest subsequence condition subsequence should in increasing order */

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(vector<int>&nums,int prev_idx,int curr_idx) {
    if(curr_idx >= nums.size()) return 0;

    int include = 0;
    if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]) {
        include = 1 + solveUsingRecursion(nums,curr_idx,curr_idx+1);
    }
    int exclude = 0 + solveUsingRecursion(nums,prev_idx,curr_idx+1);

    return max(include,exclude);

}


int solveUsingMemoisation(vector<int>&nums,int prev_idx,int curr_idx,vector<vector<int>>&dp) {
    if(curr_idx >= nums.size()) return 0;

    if(dp[curr_idx][prev_idx+1] != -1) return dp[curr_idx][prev_idx+1];     // step 3 : if ans exist return it

    int include = 0;
    if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]) {
        include = 1 + solveUsingMemoisation(nums,curr_idx,curr_idx+1,dp);
    }
    int exclude = 0 + solveUsingMemoisation(nums,prev_idx,curr_idx+1,dp);

    dp[curr_idx][prev_idx+1] = max(include,exclude);    // step 2 : store the ans in  dp array

    return dp[curr_idx][prev_idx+1];
    
}

int solveUsingTabulation(vector<int>&nums) {
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));  // step 1 : create dp array , initialize it

    // step 2 : analyse base case => nth row should be equal to zero ,  that's why initilized the whole dp with 0

    for(int curr_idx=n-1; curr_idx>=0; curr_idx--) {     //step 3 : reverse flow and look for looping variables

        for(int prev_idx=curr_idx-1; prev_idx>=-1; prev_idx--) {

            int include = 0;
            if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]) {        // we created two new dp , so +1 in the prev_idx to handle overflow
                include = 1 + dp[curr_idx+1][curr_idx+1];
            }
            int exclude = 0 + dp[curr_idx+1][prev_idx+1];
            dp[curr_idx][prev_idx+1] = max(include,exclude);
        }
    }
    return dp[0][0];
}

int main() {

    int n;
    cout<<"Enter Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Value : ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    int prev_idx = -1;
    int curr_idx = 0;
    int ans = solveUsingRecursion(nums,prev_idx,curr_idx);    
    cout<<"The length : "<<ans<<endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));         // step 1 : find dp array (two parameters changing) , create it , initialize it and pass it 
    ans = solveUsingMemoisation(nums,prev_idx,curr_idx,dp);
    cout<<"The length (Memoisation ) : "<<ans<<endl;
     
    ans = solveUsingTabulation(nums);
    cout<<"The length (Tabulation) : "<<ans<<endl;

    return 0;

}