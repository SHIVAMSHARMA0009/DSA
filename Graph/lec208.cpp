/* Defence the Kingdom */
#include<bits/stdc++.h>
using namespace std;

// Brute Force Solution
int solve(int row,int col, vector<pair<int,int>>& v, int n) {

    vector<int> rowLoc;
    rowLoc.push_back(0);
    rowLoc.push_back(row+1);

    // rows
    for(int i=0; i<n; i++) {
        rowLoc.push_back(v[i].first);
    }

    sort(rowLoc.begin(), rowLoc.end());

    int maxRowDiff = INT_MIN;
    for(int i=1; i<rowLoc.size(); i++) {
        int diff = rowLoc[i] - rowLoc[i-1] - 1;
        maxRowDiff = max(maxRowDiff,diff);
    }



    vector<int> colLoc;
    colLoc.push_back(0);
    colLoc.push_back(col+1);

    for(int i=0; i<n; i++) {
        colLoc.push_back(v[i].second);
    }

    sort(colLoc.begin(), colLoc.end());

    int maxColDiff = INT_MIN;
    for(int i=1; i<colLoc.size(); i++) {
        int diff = colLoc[i] - colLoc[i-1] - 1;
        maxColDiff = max(maxColDiff,diff);
    }

    return maxRowDiff*maxColDiff;

}

int main() {

    int row, col, n;
    cout<<"Enter No of Row , col, nodes : ";
    cin>>row>>col>>n;

    vector<pair<int,int>> v(n);
    cout<<"Enter The Co-ordinates : ";
    for(int i=0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        v[i] = {a,b};
    }

    cout<<"The Maximum Panelty : "<<solve(row, col, v, n);

    return 0;

}