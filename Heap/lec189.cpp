/* merge k sorted array */

#include<bits/stdc++.h>
using namespace std;

vector<int> sortArr(vector<vector<int>>&arr) {

    vector<int>ans;

    // min_heap : {val,row,col}
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

    int r_size = arr.size();

    for(int i=0;i<r_size;i++) {
        if(!arr[i].empty()) {
            pq.push({arr[i][0],i,0});
        }
    }

    while(!pq.empty()) {

        auto t = pq.top();
        int val = get<0>(t);
        int row = get<1>(t);
        int col = get<2>(t);
        pq.pop();

        ans.push_back(val);

        if(col + 1 < arr[row].size()) {
            pq.push({arr[row][col+1],row,col+1});
        }
    }

    return ans;
}

int main() {

    int n,m;
    cout<<"Enter Size of 2D vector & no. of col : ";
    cin>>n>>m;

    cout<<"Enter Values : ";
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    vector<int>ans = sortArr(arr);

    cout<<"The Sorted : ";
    for(auto val : ans) {
        cout<<val<<" ";
    }

    return 0;

}