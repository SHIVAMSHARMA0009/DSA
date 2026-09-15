/* 0 - 1 Knapsack Problem , we are given integer W which is the weight of knapsack 
   and given weight array of n items and every item has its value in the value array 

It say -> we can only the items in the knapsack which has weight less than or equal to the weight of knapsack  
return the maximum values of all  items of the knapsack

*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int weight, vector<int>&val, vector<int>&wt, int index) {
    if(index >= wt.size()) return 0;

    // include - exclude
    int includeAns = 0;
    if(wt[index] <= weight) {
        includeAns = val[index] + knapsack(weight - wt[index],val,wt,index+1);
    }

    int excludeAns = 0 + knapsack(weight,val,wt,index+1);

    return max(includeAns,excludeAns);

}

int solveUsingMemoisation(int weight, vector<int>&val, vector<int>&wt, int index, vector<vector<int>> &dp) {
    if(index >= wt.size()) return 0;

    if(dp[weight][index] != -1) return dp[weight][index];

  
    int includeAns = 0;
    if(wt[index] <= weight) {
        includeAns = val[index] + solveUsingMemoisation(weight - wt[index],val,wt,index+1,dp);
    }

    int excludeAns = 0 + solveUsingMemoisation(weight,val,wt,index+1,dp);

    int ans =  max(includeAns,excludeAns);

    dp[weight][index] = ans;

    return ans;
}

int solveUsingTabulation(int weight, vector<int>&val, vector<int>&wt) {

    int n = wt.size();
    vector<vector<int>> dp(weight+1,vector<int>(n+1,0));

    // after analyzing base case , we came to know that for index = n , we need to set 0 as answer 

    for(int a=0; a<=weight; a++) {
        for(int i=n-1; i>=0; i--) {
            int includeAns = 0;
            if(wt[i] <= a) {
                includeAns = val[i] + dp[a - wt[i]][i+1];
            }
            int excludeAns = 0 + dp[a][i+1];
            int ans =  max(includeAns,excludeAns);
            dp[a][i] = ans;
        }
    }

    return dp[weight][0];

}

int solveUsingSO(int weight, vector<int>&val, vector<int>&wt) {

    int n = wt.size();
    
    vector<int> curr(weight+1,0);
    vector<int> next(weight+1,0);

    // after analyzing base case , we came to know that for index = n , we need to set 0 as answer 

    for(int i=n-1; i>=0; i--) {           // changed the order -> we want movement to every row of a column
        for(int a=0; a<=weight; a++) {
            int includeAns = 0;
            if(wt[i] <= a) {
                includeAns = val[i] + next[a - wt[i]];
            }
            int excludeAns = 0 + next[a];
            int ans =  max(includeAns,excludeAns);
            curr[a] = ans;
        }
        next = curr;
    }

    return curr[weight];

}

int solveUsingSO1(int weight, vector<int>&val, vector<int>&wt) {

    int n = wt.size();
    
    vector<int> next(weight+1,0);

    // after analyzing base case , we came to know that for index = n , we need to set 0 as answer 

    for(int i=n-1; i>=0; i--) {           // changed the order -> we want movement to every row of a column

        // row
        for(int a=weight; a>=0; a--) {      // bcz row ans of current col depens upon its upper rows of same col -> that's why we reverse the traversal
            int includeAns = 0;
            if(wt[i] <= a) {
                includeAns = val[i] + next[a - wt[i]];
            }
            int excludeAns = 0 + next[a];
            int ans =  max(includeAns,excludeAns);
            next[a] = ans;
        }
        // next = curr;
    }

    return next[weight];

}



int main() {

    int W;
    cout<<"Enter Weight of Knapsack : ";
    cin>>W;

    int n;
    cout<<"Enter No. of items : ";
    cin>>n;

    vector<int>val(n);
    cout<<"Enter Value of items : ";
    for(int i=0;i<n;i++) {
        cin>>val[i];
    }

    vector<int>wt(n);
    cout<<"Enter Weight of items : ";
    for(int i=0;i<n;i++) {
        cin>>wt[i];
    }
    
    int ans = knapsack(W,val,wt,0);
    cout<<"The Maximum sum of Values : "<<ans<<endl;

    vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
    ans = solveUsingMemoisation(W,val,wt,0,dp);
    cout<<"The Maximum sum of Values (Memoisation) : "<<ans<<endl;

    ans = solveUsingTabulation(W,val,wt);
    cout<<"The Maximum sum of Values (Tabulation) : "<<ans<<endl;

    ans = solveUsingSO(W,val,wt);
    cout<<"The Maximum sum of Values (SO) : "<<ans<<endl;

    ans = solveUsingSO1(W,val,wt);
    cout<<"The Maximum sum of Values (SO1) : "<<ans<<endl;

    return 0;

}