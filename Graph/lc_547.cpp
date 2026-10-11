/* we are given n cities , if city A is directly connected with city B and city B is directly connected with city C , means city A is directly connected with city C */
/* also given n X n  matrix , where if i and j are connected [i][j] = 1 and [i][j] = 0 */
/* give total provinces (group of directly and indirectly connected cities) */

#include<bits/stdc++.h>
using namespace std;

void dfs(int src,unordered_map<int,bool>&vis,int n,vector<vector<int>>&isConnected) {
    vis[src] = true;
    // node ke neighbour ko visited mark kro  aur wo row ke col me milenge
    int col = n;
    int row = src;
    for(int nbrIndex=0; nbrIndex<col; nbrIndex++) {
        int nbr = nbrIndex;
        if(isConnected[row][nbrIndex] == 1) {
            if(!vis[nbr]) {
                dfs(nbr,vis,n,isConnected);
            }
        }
    }
}

int findCircleNUm(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int count = 0;
    unordered_map<int,bool>vis;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i,vis,n,isConnected);
            count++;
        } 
    }
    return  count;
}

int main() {
    int n;
    cout<<"Enter The Size : ";
    cin>>n;

    cout<<"Enter The Data of Node : ";
    vector<vector<int>>nums(n,vector<int>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>nums[i][j];
        }
    }

    cout<<"The Provinces : "<<findCircleNUm(nums);

    return 0;
    
}