/* we are given an array , Divide the array into two parts such that their sums are equal */

#include<bits/stdc++.h>
using namespace std;

/* if we divide array into two parts -> this means array sum will split into two parts */

/* T.C : O(2^n) */
bool partitionUsingRecursion(vector<int>&nums,int target,int index) {

    int n = nums.size();

    if(index >= n) return 0;
    if(target < 0)  return 0;
    if(target == 0) return 1;

    // include - exclude -> bcz we to check at every value , are we able to make target as 0
    bool include = partitionUsingRecursion(nums,target-nums[index],index+1);
    bool exclude = partitionUsingRecursion(nums,target,index+1);

    bool ans = include || exclude;

    return ans;
}


/* T.C : O(n*m)   ||   S.C : O(n*m) */
bool partitionUsingMemoisation(vector<int>&nums,int target,int index,vector<vector<int>>&dp) {

    int n = nums.size();

    if(index >= n) return 0;
    if(target < 0)  return 0;
    if(target == 0) return 1;

    if(dp[index][target] != -1) return dp[index][target];

    // include - exclude -> bcz we to check at every value , are we able to make target as 0
    bool include = partitionUsingMemoisation(nums,target-nums[index],index+1,dp);
    bool exclude = partitionUsingMemoisation(nums,target,index+1,dp);

    bool ans = include || exclude;

    dp[index][target] = ans;

    return ans;
}


/* T.C : O(n*m)   ||   S.C : O(n*m) */
bool partitionUsingTabulation(vector<int>&nums,int target) {

    int n = nums.size();
    vector<vector<int>>dp(target+1,vector<int>(n+1,0));    // step 1 : find dp array , create it

    for(int i=0;i<nums.size();i++) {    // step 2 : analyse base cases
        dp[0][i] = 1;
    }

    for(int t=1; t<=target; t++) {                      // step 3 : reverse the flow and take care of looping variables
        for(int index=n-1; index>=0; index--) {
    
            bool include = 0;
            if(t-nums[index] >= 0)
                include = dp[t-nums[index]][index+1];

            bool exclude = dp[t][index+1];

            bool ans = include || exclude;
            dp[t][index] = ans;

        }
    }

    return dp[target][0];      // step 4

}

/* T.C : O(n*m)   ||   S.C : O(n+m) */
bool partitionUsingSO(vector<int>&nums,int target) {

    int n = nums.size();
    
    vector<int> curr(target+1,0);
    vector<int> next(target+1,0);

    curr[0] = 1;
    next[0] = 1;

    for(int index=n-1; index>=0; index--) {
        for(int t=1; t<=target; t++) {
            bool include = 0;                                  // here every row depends upon the next row for its column ans
            if(t - nums[index] >= 0) {
                include = next[t-nums[index]];
            }
            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        next = curr;
    }

    return next[target]; 

}

int main() {

    int n;
    cout<<"Enter Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array Value : ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    int sum = accumulate(nums.begin(),nums.end(),0);

    if(sum & 1) {
        cout<<"Can't Divide !";    // IMP : if sum is odd , then how can we divide into 2 equal parts
        return 0;
    }

    int target = sum/2;
    int index = 0;

    cout<<"Can we divide ? "<<partitionUsingRecursion(nums,target,index)<<endl;

    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    cout<<"Can we divide (Memoisation) ? "<<partitionUsingMemoisation(nums,target,index,dp)<<endl;

    cout<<"Can we divide (Tabulation) ? "<<partitionUsingTabulation(nums,target)<<endl;

    cout<<"Can we divide (SO) ? "<<partitionUsingSO(nums,target)<<endl;

    return 0;

}