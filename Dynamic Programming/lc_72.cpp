/* we are given two  string , we have to return the minimum no. of operations required to convert first string to second string */
/* we can perform the three at one time -> insert ,delete and replace the character */

#include<bits/stdc++.h>
using namespace std;

int solveUsingRecursion(string &first,string &second,int i,int j) {
    if(i == first.length())  return second.length() - j; 
    if(j == second.length()) return first.length() - i;

    int ans = 0;
    if(first[i] == second[j]) {
        ans = solveUsingRecursion(first,second,i+1,j+1);   // if match found , no need to perform any operation
    }
    else{
        int insert = 1 + solveUsingRecursion(first,second,i,j+1);    
        int deleted = 1 + solveUsingRecursion(first,second,i+1,j);
        int replace = 1 + solveUsingRecursion(first,second,i+1,j+1);
        ans = min(insert,min(deleted,replace));
    }
    return ans;
}

int solveUsingMemoisation(string &first,string &second,int i,int j,vector<vector<int> >&dp) {
    if(i == first.length())  return second.length() - j; 
    if(j == second.length()) return first.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(first[i] == second[j]) {
        ans = solveUsingMemoisation(first,second,i+1,j+1,dp);   // if match found , no need to perform any operation
    }
    else{
        int insert = 1 + solveUsingMemoisation(first,second,i,j+1,dp);    
        int deleted = 1 + solveUsingMemoisation(first,second,i+1,j,dp);
        int replace = 1 + solveUsingMemoisation(first,second,i+1,j+1,dp);
        ans = min(insert,min(deleted,replace));
    }

    dp[i][j] = ans;

    return ans;
}


int solveUsingTabulation(string &first,string &second) {

    vector<vector<int> >dp(first.length()+1,vector<int>(second.length()+1,0));

    for(int j = 0; j <= second.length(); j++) {
        dp[first.length()][j] = second.length() - j;
    }

    for(int i = 0; i <= first.length(); i++) {
        dp[i][second.length()] = first.length() - i;
    }

    for(int i=first.length()-1; i>=0; i--) {
        for(int j=second.length()-1; j>=0; j--) {
            int ans = 0;
            if(first[i] == second[j]) {
                ans = dp[i+1][j+1];   // if match found , no need to perform any operation
            }
            else{
                int insert = 1 + dp[i][j+1];    
                int deleted = 1 + dp[i+1][j];
                int replace = 1 + dp[i+1][j+1];
                ans = min(insert,min(deleted,replace));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}


int solveUsingSO(string &first,string &second) {

    vector<int>curr(second.length()+1,0);
    vector<int>next(second.length()+1,0);

    for(int j = 0; j <= second.length(); j++) {
        next[j] = second.length() - j;               // dp ke ander sabse last wali row will be our next array
    }

    
    for(int i=first.length()-1; i>=0; i--) {

        // every row starts here
        curr[second.length()] = first.length()-i;        // dp ke har row ke last column ke ander

        for(int j=second.length()-1; j>=0; j--) {
            int ans = 0;
            if(first[i] == second[j]) {
                ans = next[j+1];   // if match found , no need to perform any operation
            }
            else{
                int insert = 1 + curr[j+1];    
                int deleted = 1 + next[j];
                int replace = 1 + next[j+1];
                ans = min(insert,min(deleted,replace));
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return curr[0];
}



int main() {

    string first;
    cout<<"Enter First Word : ";
    cin>>first;

    string second;
    cout<<"Enter Second Word : ";
    cin>>second;

    if(first.length() == 0) return second.length();
    if(second.length() == 0) return  first.length();

    int i = 0;
    int j = 0;

    cout<<"The Minimum Operations : "<<solveUsingRecursion(first,second,i,j)<<endl;

    vector<vector<int> >dp(first.length()+1,vector<int>(second.length()+1,-1));
    cout<<"The Minimum Operations (Memoisation) : "<<solveUsingMemoisation(first,second,i,j,dp)<<endl;

    cout<<"The Minimum Operations (Tabulation) : "<<solveUsingTabulation(first,second)<<endl;

    cout<<"The Minimum Operations (SO) : "<<solveUsingSO(first,second)<<endl;

    return 0;

}