/* we are given houses in a street with their amount , we have to maximize the robbery only condition is that we can't rob adjacent houses */

#include<bits/stdc++.h>
using namespace std;

// T.C : O(2^n)     ||     S.C : O(n)
int solveUsingRecursion(vector<int>nums,int index) {
    if(index >=  nums.size()) {
        return 0;
    }

    int include = nums[index] + solveUsingRecursion(nums,index+2);
    int exclude = 0 + solveUsingRecursion(nums,index+1);

    return max(include,exclude);

}

//  T.C : O(n)    ||   S.C : O(n)
int solveUsingMemoisation(vector<int>nums,int index,vector<int>&dp) {
    if(index >=  nums.size()) {
        return 0;
    }

    if(dp[index] != -1) return dp[index];                 // step 3 : if ans exist , return it

    int include = nums[index] + solveUsingMemoisation(nums,index+2,dp);
    int exclude = 0 + solveUsingMemoisation(nums,index+1,dp);
    dp[index] = max(include,exclude);                    // step 2 : store the ans into dp  array

    return dp[index];
}

int solveUsingTabulation(vector<int>&nums) {
    int n = nums.size();

    vector<int>dp(n+1,-1);         // step 1 : find dp array , create it and initialize it

    dp[n] = 0;                     // step 2 : analyse the base case 

    for(int i=n-1;i>=0;i--) {             // step 3 : reverse the flow
        
        int temp = 0; 
        if(i+2 <= n){               // IMP : suppose i = n-1 -> temp[i+2] = temp[n+1] which is invalid bcz indexes are from 0->n
            temp = dp[i+2];
        }

        int include = nums[i] + temp;
        int exclude = 0 + dp[i+1];
        dp[i] = max(include,exclude); 
    }
    return dp[0];   // return ans
}

int solveUsingSpaceOptimization(vector<int>&nums) {
    int n = nums.size();

    int next1 = 0;                     // why ? our current answer was only dependent on the next two positions     
    int next2 = 0;
    int curr;

    for(int i=n-1;i>=0;i--) {             

        int include = nums[i] + next2;
        int exclude = 0 + next1;
        curr = max(include,exclude); 

        next2 = next1;               // IMP : shifting -> highly chances of  getting forget
        next1 = curr;
    }

    return curr;   // return ans
}

int main() {

    int n;
    cout<<"Enter Vector Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Value : ";
    for(int i=0;i<nums.size();i++) {
        cin >> nums[i];
    }

    
    int ans = solveUsingRecursion(nums,0);
    cout<<"The Maximum Robbery : "<<ans<<endl;

    vector<int>dp(n+1,-1);                        // step 1 : find dp array , create it , initialize it and pass it         
    ans = solveUsingMemoisation(nums,0,dp);
    cout<<"The Maximum Robbery (Memoisation) : "<<ans<<endl;

    ans = solveUsingTabulation(nums);
    cout<<"The Maximum Robbery (Tabulation) : "<<ans<<endl;

    ans = solveUsingSpaceOptimization(nums);
    cout<<"The Maximum Robbery (Space Optimization) : "<<ans<<endl;

    return 0;

}