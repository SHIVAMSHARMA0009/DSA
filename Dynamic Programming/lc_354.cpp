/* we are given 2D array , each array has width and height , give the maximum number if envolpoes which we can push inside the other */

/* PATTERN SAME AS LONGEST INCREASING SUBSEQUENCES -> larger then smaller then smalerr .... */

#include<bits/stdc++.h>
using namespace std;

// APPROACH 1
bool check(vector<int>&curr,vector<int>&prev) {
    // curr -> bade wala && prev -> chote wala
    if(prev[0] < curr[0] && prev[1] < curr[1]) {
        return true;
    }
    return false;
}

int solveUsingTabulation(vector<vector<int>>& enevelops) {

    int n = enevelops.size();
    vector<int>currRow(n+1,0);
    vector<int>nextRow(n+1,0);

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0;

            if(prev == -1 || check(enevelops[curr],enevelops[prev])) { // if condition is true
                include = 1 + nextRow[curr+1];      // increase the count of enevelop
            }

            int exclude = 0 + nextRow[prev+1];
            currRow[prev+1] = max(include,exclude);
        }
        nextRow = currRow;
    }
    return currRow[0];
}

int maxEnvelopes(vector<vector<int>>&enevelops) {

    sort(enevelops.begin(),enevelops.end());        
    int ans = solveUsingTabulation(enevelops);
    return ans;
}



// APPROACH 2 
static bool cmp(vector<int> &a, vector<int> &b) {
    // If the widths are equal, sort in descending order of heights
    if (a[0] == b[0]) {
        return a[1] > b[1];
    }

    // Sort in ascending order of widths
    return a[0] < b[0];
}

int solveBS(int n,vector<vector<int>>& nums) {
    sort(nums.begin(),nums.end(),cmp);

    vector<int> ans;
    ans.push_back(nums[0][1]);

    for(int i=1;i<n;i++) {
        if(nums[i][1]>ans.back()) ans.push_back(nums[i][1]);
        else {
            //find index of just bada element in ans
            int index=lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin();
            ans[index]=nums[i][1];
        }
    }
    return ans.size();
}    

int maxEnvelopesBS(vector<vector<int>>& envelopes) {
    int n=envelopes.size();
    return solveBS(n,envelopes);      
}

int main() {

    int n;
    cout<<"Enter Number of Envelops : ";
    cin>>n;

    vector<vector<int>>enevelops(n,vector<int>(2));
    cout<<"Enter Each Envelop Dimension : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            cin>>enevelops[i][j];
        }
    }

    int ans = maxEnvelopes(enevelops);
    cout<<"The Maximum Enevelops : "<<ans<<endl;

    int ans = maxEnvelopesBS(enevelops);
    cout<<"The Maximum Enevelops : "<<ans<<endl;

    return 0;
}