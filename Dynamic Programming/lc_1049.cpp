/* we given integer array where every value represents the stone's weight */
/* we have to crush two stones at a time , if two stones are equal they will completely destroy each other 
   if not equal larger one will have some left part , so find smallest possible weight that can be left out */

/* APPROACH : At every index , we will perform two operations , either we will add current weight or subtract */

#include<bits/stdc++.h>
using namespace std;


int solveUsingRecursion(vector<int>& stones,int i,int sum) {
    if(i == stones.size()) {
        if(sum < 0) return INT_MAX;     // here , we will be ignoring the negative value
        return sum;
    }

    // we will have two option either add the current or  subtract the current

    // option 1 : ADD
    int pos = solveUsingRecursion(stones,i+1,sum + stones[i]);

    // option 2 : SUBTRACT
    int neg = solveUsingRecursion(stones,i+1,sum - stones[i]);

    return min(pos,neg);

}


int solveUsingMemoisation(vector<int>& stones,int i,int sum,vector<vector<int>> &dp) {

    int totalsum = accumulate(stones.begin(),stones.end(),0);

    if(i == stones.size()) {
        if(sum < 0) return INT_MAX;     // here , we will be ignoring the negative value
        return sum;
    }

    if(dp[i][sum + totalsum] != -1) return dp[i][sum + totalsum];

    // we will have two option either add the current or  subtract the current

    // option 1 : ADD
    int pos = solveUsingMemoisation(stones,i+1,sum + stones[i],dp);

    // option 2 : SUBTRACT
    int neg = solveUsingMemoisation(stones,i+1,sum - stones[i],dp);

    dp[i][sum+totalsum] =  min(pos,neg);

    return dp[i][sum+totalsum];

}


int solveUsingTabulation(vector<int>& stones) {
    
    int n = stones.size();
    int totalsum = accumulate(stones.begin(),stones.end(),0);
    vector<vector<int>> dp(n+1,vector<int>(2*totalsum+1,0));

    for(int sum = -totalsum;sum <= totalsum; sum++) {
        dp[n][sum + totalsum] = sum < 0 ? INT_MAX : sum;                 // base cases
    }

    for(int i=stones.size()-1;i>=0; i--) {
        for(int j=totalsum;j>=-totalsum; j--) {

            int pos = INT_MAX, neg = INT_MAX;

            if(j + stones[i] <= totalsum)
                pos = dp[i+1][totalsum + j + stones[i]];

            if(j - stones[i] >= -totalsum)
                neg = dp[i+1][totalsum + j - stones[i]];

            dp[i][j + totalsum] =  min(pos,neg);
        }
    }

    return dp[0][totalsum];

}


int solveUsingSO(vector<int>& stones) {
    
    int n = stones.size();
    int totalsum = accumulate(stones.begin(),stones.end(),0);
    
    vector<int>curr(2*totalsum+1,0);
    vector<int>next(2*totalsum+1,0);

    for(int sum = -totalsum;sum <= totalsum; sum++) {
        next[sum + totalsum] = sum < 0 ? INT_MAX : sum;                 // base cases
    }

    for(int i=stones.size()-1;i>=0; i--) {
        for(int j=totalsum;j>=-totalsum; j--) {

            int pos = INT_MAX, neg = INT_MAX;

            if(j + stones[i] <= totalsum)
                pos = next[totalsum + j + stones[i]];

            if(j - stones[i] >= -totalsum)
                neg = next[totalsum + j - stones[i]];

            curr[j + totalsum] =  min(pos,neg);
        }
        next = curr;
    }

    return curr[totalsum];

}



int main() {

    int n;
    cout<<"Enter The Number Of Stones : ";
    cin>>n;

    vector<int> stones(n);
    cout<<"Enter The Weight : ";
    for(int i=0;i<n;i++) {
        cin >> stones[i];
    }

    int totalsum = accumulate(stones.begin(),stones.end(),0);

    int i = 0;
    int sum = 0;
    cout<<"The Minimum Left Part : "<<solveUsingRecursion(stones,i,sum)<<endl;


    vector<vector<int>> dp(n+1,vector<int>(2*totalsum+1,-1));
    cout<<"The Minimum Left Part (Memoisation) : "<<solveUsingMemoisation(stones,i,sum,dp)<<endl;

    cout<<"The Minimum Left Part (Tabulation) : "<<solveUsingTabulation(stones)<<endl;

    cout<<"The Minimum Left Part (SO) : "<<solveUsingSO(stones)<<endl;


    return 0;

}