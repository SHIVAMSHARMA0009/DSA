/* we are given an array which contains leaf nodes of tree in an in-order traversal , tree will be having 0 or 2 children only */
/* The value of each NON-LEAF NODE will be equal to the product of largest leaf node from left & right subtree */

/* so among all possible binary tree formed from these this array , we have to return smallest sum of NON-LEAF nodes among all the tree */

#include<bits/stdc++.h>
using namespace std;

/* APPRAOCH : we can divide the array into two parts , so will be having n(size of array) choices to divide the array and then will store will the maximum value of every range*/
/* after that we will take one leaf node and find product of maximum of left and right through the map which will give the parent node value 
   and then  recursively we will find the the sum of non-leaf node  from its left subtree and right sub tree and then add it and return min */


int solveUsingRecursion(vector<int>& arr,map<pair<int,int>,int>maxi,int left,int right) {
    if(left == right) return 0;

    int ans = INT_MAX;
    for(int i=left;i<right;i++) {

/*                    max-leftStree   max-rightStree            sum-leftStree                      sum-RightStree                                */
        ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveUsingRecursion(arr,maxi,left,i) + solveUsingRecursion(arr,maxi,i+1,right));

    }

    return ans;
}


int solveUsingMemoisation(vector<int>& arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp) {
    if(left == right) return 0;

    if(dp[left][right] != -1) return dp[left][right];

    int ans = INT_MAX;
    for(int i=left;i<right;i++) {
        ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveUsingMemoisation(arr,maxi,left,i,dp) + solveUsingMemoisation(arr,maxi,i+1,right,dp));
    }

    dp[left][right] = ans;

    return dp[left][right];
}


int solveUsingTabulation(vector<int>& arr,map<pair<int,int>,int>&maxi) {
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int left=n-1;left>=0;left--) {
        for(int right=0;right<=n-1;right++) {

            if(left >= right) continue;
                
            int ans = INT_MAX;
            for(int i=left;i<right;i++) {
                ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);     
            }
            dp[left][right] = ans;
        }
    }
    return dp[0][n-1];
}


int main() {

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter The Value of Array : ";
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    map<pair<int,int>,int>maxi;


    for(int i=0; i<n; i++) {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<n; j++) {
            maxi[{i,j}] = max(arr[j],arr[i,j-1]);
        }
    }

    cout<<"The Smallest Sum : "<<solveUsingRecursion(arr,maxi,0,n-1)<<endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<"The Smallest Sum (Memoisation) : "<<solveUsingMemoisation(arr,maxi,0,n-1,dp)<<endl;

    cout<<"The Smallest Sum (Tabulation) : "<<solveUsingTabulation(arr,maxi);

    return 0;
    
}