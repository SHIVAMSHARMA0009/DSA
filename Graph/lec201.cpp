/* Kruskal's Algorithm */
#include<bits/stdc++.h>
using namespace std;

static bool mycmp(vector<int>&a,vector<int>&b) {
    return a[2] < b[2];   // return the smallest element at index 2 -> so that sorting will be increasing order
}

int findParent(vector<int>&parent , int node) {
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent,parent[node]);    // path compression
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank) {
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
        rank[v]++;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

int MSTKruskals(int V,vector<vector<int>>& edges) {
    
    vector<int>parent(V);    // stores last parent  e.g 2<-3<-1<-5   => parent of 5 is 1
    vector<int>rank(V,0);   // how many nodes indirectly or directly attched to any node

    for(int u=0; u<V; u++) {
        parent[u] = u;
    }

    sort(edges.begin(),edges.end(),mycmp);

    int ans = 0;
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        u = findParent(parent,u);
        v = findParent(parent,v);

        if(u != v) {
            unionSet(u, v, parent, rank);
            ans += wt;
        }
    }
    return ans;
}

int main() {

    int V,E;
    cout<<"Enter Number Of Nodes & Edges : ";
    cin>>V>>E;

    vector<vector<int>> edges(E,vector<int>(3));
    cout<<"Enter Nodes Data : ";
    for(int i=0; i<E; i++) {          
        for(int j=0; j<3; j++) {   // {u,v,wt}
            cin>>edges[i][j];
        }
    }

    cout<<"The Sum oF minimum Spanning Tree : "<<MSTKruskals(V, edges);

    return 0;

}