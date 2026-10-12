/* Bridge in a Graph [Tarjan's Algorithm] */

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int,list<int>> adjList;
    void addEdges(int u,int v,bool direction) {
        if(direction == 1) {
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList(int n) {
        for(int i=0; i<n; i++) {
            cout<<i<<" -> {";
            for(auto nbr : adjList[i]) {
                cout<<nbr<<" ";
            }
            cout<<"}"<<endl;
        }
    }

    void countBridge(int src,int parent, vector<int>&tin, vector<int>&low,unordered_map<int,bool>&vis,int timer) {
        timer++;
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;

        //neighbours per travel kro
        for(auto nbr : adjList[src]) {
            // neighbours can be parent bcz of undirected graph
            if(nbr == parent) {
                continue;
            }
            else if(!vis[nbr]) {
                // normal tarverse and check for bridge
                countBridge(nbr, src, tin, low, vis, timer);
                low[src] = min(low[src],low[nbr]);
                if(low[nbr] > tin[src]) {
                    // bridge exist
                    cout<<"Bridge Found : ";
                    cout<<nbr<<"-"<<src<<endl;
                }
            }
            else{
                //already visited
                // low time ko update kro if possible
                low[src] = min(low[src],low[nbr]);
            }
        }
    }
};

int main() {

    Graph g;
    g.addEdges(0,1,0);
    g.addEdges(1,2,0);
    g.addEdges(0,2,0);
    g.addEdges(1,3,0);
    g.addEdges(3,4,0);
    int n = 5;
    g.printAdjList(n);


    int timer = 0;
    int src = 0;
    int parent = -1;
    vector<int>tin(n);
    vector<int>low(n);
    unordered_map<int,bool>vis;
    g.countBridge(src,parent,tin,low,vis,timer);
    
    return 0;
    
}