/* given the integer n , return its fibonacci number */

#include<bits/stdc++.h>
using namespace std;

// T.C : O(2^n)    ||   S.C : O(n)
int fibonacciUsingRecursion(int n) {

    if(n == 0) return 0;
    if(n == 1) return 1;

    int ans = fibonacciUsingRecursion(n-1) + fibonacciUsingRecursion(n-2);

    return ans;
}



// T.C : O(n)    ||  S.C : O(n)
int fibonacciUsingMemoisation(int n,vector<int>&dp) {

    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];     // step 3 : if ans exist , then return it

    int ans = fibonacciUsingMemoisation(n-1,dp) + fibonacciUsingMemoisation(n-2,dp);
    dp[n] = ans;      // step 2 : store the ans to solve the overlapping problem (means if same call found again , immediately return its value)

    return dp[n];
}



// T.C : O(n)    ||  S.C : O(n)
int fibonacciUsingTabulation(int n) {
    vector<int>dp(n+1,-1);                  // step 1 : find dp type to store the result , create it , initialize it and pass it

    if(n == 0) return 0;                    // IMP : suppose if n = 0 -> create dp if size 1 , so line no. 42 will throw ans error
    if(n == 1) return 1;

    dp[0] = 0;                             // step 2 : initialize base cases
    dp[1] = 1;    

    for(int i=2;i<=n;i++){

        int ans = dp[i-1] + dp[i-2];   // step 3 : convert calling function into dp-array and change looping variable
        dp[i] = ans;
    }

    return dp[n];                     // step 4 : return dp

}



// T.C : O(n)    ||  S.C : O(1)
int fibonacciUsingSpaceOptimization(int n) {

    if(n == 0) return 0;                    
    if(n == 1) return 1;

    int prev2 = 0;                             
    int prev1 = 1;
    int curr = -1;    

    for(int i=2;i<=n;i++){

        curr = prev1 + prev2;   
        prev2 = prev1;
        prev1 = curr;

    }

    return curr;                     

}



int main() {

    int n;
    cout<<"Enter Integer Number : ";
    cin>>n;

    int ans = fibonacciUsingRecursion(n);
    cout<<"The Answer Using Recursion : "<<ans<<endl;


    vector<int>dp(n+1,-1);                        // step 1 : find dp type to store the result , create it , initialize it and pass it
    ans = fibonacciUsingMemoisation(n,dp);
    cout<<"The Answer Using Memoisation (top-down Approach) : "<<ans<<endl;

    ans = fibonacciUsingTabulation(n);
    cout<<"The Answer Using tabulation/iterative (bottom-up Approach) : "<<ans<<endl;

    ans = fibonacciUsingSpaceOptimization(n);
    cout<<"The Answer Using Space Optimization : "<<ans<<endl;

    return 0;

}