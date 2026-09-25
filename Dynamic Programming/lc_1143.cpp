/* we are given two strings , we have to found the longest common subsequence in this two strings */
/* SUBSEQUENCE ? => taking out characters and arranging them while considering that they should be in the as of original string */

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(string text1, string text2, int i, int j) {
    if(i == text1.length()) return 0;
    if(j == text2.length()) return 0;

    int ans = 0;

    if(text1[i] == text2[j]) {    // case 1 : if both the characters are equals  -> check for rest of strings from both
        ans = 1 + solveUsingRecursion(text1, text2, i+1, j+1);
    }
    else {        // case 2 : we can exclude character from any of the string but need maximum of it
        ans = 0 + max(solveUsingRecursion(text1,text2,i+1,j),solveUsingRecursion(text1,text2,i,j+1));
    }

    return ans;
}

int solveUsingMemoisation(string &text1, string &text2, int i, int j, vector<vector<int>>&dp) {
    if(i == text1.length()) return 0;
    if(j == text2.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if(text1[i] == text2[j]) {    
        ans = 1 + solveUsingMemoisation(text1, text2, i+1, j+1, dp);
    }
    else {       
        ans = 0 + max(solveUsingMemoisation(text1,text2,i+1,j, dp),solveUsingMemoisation(text1,text2,i,j+1, dp));
    }

    dp[i][j] = ans;

    return dp[i][j];
}

int solveUsingTabulation(string &text1, string &text2) {
    vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));

    for(int i=text1.length()-1; i>=0; i--) {
        for(int j=text2.length()-1; j>=0; j--) {
            int ans = 0;
            if(text1[i] == text2[j]) {    
                ans = 1 +  dp[i+1][j+1];
            }
            else {       
                ans = 0 + max(dp[i+1][j],dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveUsingSO(string &text1, string &text2) {
    vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,0));

    vector<int>curr(text2.length()+1,0);
    vector<int>next(text2.length()+1,0);

    for(int i=text1.length()-1; i>=0; i--) {
        for(int j=text2.length()-1; j>=0; j--) {
            int ans = 0;
            if(text1[i] == text2[j]) {    
                ans = 1 +  next[j+1];
            }
            else {       
                ans = 0 + max(next[j],curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return curr[0];
}

int main() {

    string text1;
    cout<<"Enter 1st String : ";
    cin>>text1;

    string text2;
    cout<<"Enter 2nd String : ";
    cin>>text2;

    int i = 0;
    int j = 0;

    cout<<"The Longest Common Subsequence : "<<solveUsingRecursion(text1,text2,i,j)<<endl;

    vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
    cout<<"The Longest Common Subsequence (Memoisation) : "<<solveUsingMemoisation(text1,text2,i,j,dp)<<endl;

    cout<<"The Longest Common Subsequence (Tabulation) : "<<solveUsingTabulation(text1,text2)<<endl;

    cout<<"The Longest Common Subsequence (S.O) : "<<solveUsingSO(text1,text2)<<endl;

    return 0;

}