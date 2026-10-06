#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newX, int newY, int row, int col, vector<vector<int>>& diff, int currX, int currY) {
    if(newX >= 0 && newY >= 0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) {
        return true;
    }
    return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> mini;
    int row = heights.size();
    int col = heights[0].size();

    vector<vector<int>> diff(row,vector<int>(col,INT_MAX));
    int destX = row-1;
    int destY = col-1;

    // initial state
    // set source distance as 0
    diff[0][0] = 0;

    // push source into min heap
    mini.push({0,{0,0}});

    while(!mini.empty()) {

        auto topPair = mini.top();
        mini.pop();

        int currDiff = topPair.first;
        pair<int,int> currNodeIndexPair = topPair.second;
        int currX = currNodeIndexPair.first;
        int currY = currNodeIndexPair.second;

        // from current co-ordinates , we can travel to all nbrs -> top , down , left , right

        int dx[] = {-1,0,1,0};   // {top,right,down,left}
        int dy[] = {0,1,0,-1};

        for(int i=0;i<4;i++) {        // by using this , we will go to all possible 4 directions from the current position
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if(isSafe(newX, newY, row, col, diff, currX, currY)) {   // now will check , Is it ok to move 

                int maxDiff = max(currDiff,abs(heights[currX][currY] - heights[newX][newY]));  // look for max diff in the current path
                diff[newX][newY] = min(diff[newX][newY],maxDiff);  // update the difference array

                if(newX != destX || newY != destY) {
                    mini.push({diff[newX][newY],{newX,newY}});   // update the heap
                }

            }
        }

    }

    return diff[destX][destY];

}

int main() {

    int n;
    cout<<"Enter The  no. of Heights : ";
    cin>>n;

    vector<vector<int>>heights(n,vector<int>(n));
    cout<<"Enter The Heights : ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>heights[i][j];
        }
    }

    cout<<"The Minimum Difference Path : "<<minimumEffortPath(heights);

    return 0;
}