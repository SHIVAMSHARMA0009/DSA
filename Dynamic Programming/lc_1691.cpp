/* given n cuboids with their width , length and height , we can place the over another if it has all three dimensions less than the other , 
   give the maximum height */

#include<bits/stdc++.h>
using namespace std;

/* SAME PATTERN LONGEST INCREASING SUBSEQUENCES as we have keep the cuboids larger then smaller then smaller.....*/

bool check(vector<int>&curr,vector<int>&prev) {
    // curr -> bade wala && prev -> chote wala
    if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) {
        return true;
    }
    return false;
}

int solveUsingTabulation(vector<vector<int>>& cuboids) {

    int n = cuboids.size();
    vector<int>currRow(n+1,0);
    vector<int>nextRow(n+1,0);

    for(int curr=n-1; curr>=0; curr--) {
        for(int prev=curr-1; prev>=-1; prev--) {
            int include = 0;
            if(prev == -1 || check(cuboids[curr],cuboids[prev])) {
                int height = cuboids[curr][2];
                include = height + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];
            currRow[prev+1] = max(include,exclude);
        }
        nextRow = currRow;
    }
    return currRow[0];
}

int maxHeight(vector<vector<int>>& cuboids) {

    for(auto &cuboid : cuboids) {
        sort(cuboid.begin(),cuboid.end());           // to get maximum height we will sort each array so that 
                                                     // last index of each array has maximum number which will represent the height
    }

    sort(cuboids.begin(),cuboids.end());             // now sort overall 2d vectore so that it will be smaller width then larger then  larger
    int ans = solveUsingTabulation(cuboids);
    return ans;
}

int main() {

    int n;
    cout<<"Enter Number of Cuboids : ";
    cin>>n;

    vector<vector<int>>cuboids(n,vector<int>(3));
    cout<<"Enter Each Cuboid Dimension : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>cuboids[i][j];
        }
    }

    int ans = maxHeight(cuboids);
    cout<<"The MaxHeight : "<<ans<<endl;

    return 0;
}