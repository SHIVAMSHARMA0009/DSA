/* Cycle detection */
#include<bits/stdc++.h>
using namespace std;


class Graph{               

    public:
    // adjacency List
    unordered_map<int,vector<int>> adjList;

    // direction = 1 -> directed edge
    // direction = 0 -> undirected edge
    void addEdge(int u, int v, bool direction) {
        if(direction == 1) {
            // directed edge => u->v
            adjList[u].push_back(v);
        }
        else{
            // undirected edge
            // u--v == v--u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }



    // DFS Approach (DIRECTED)

    bool  dfsCycle_D(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsTracker) {
        visited[src] = true;
        dfsTracker[src] = true;

        for(auto nbr : adjList[src]) {
           if(!visited[nbr]) {
                if(dfsCycle_D(nbr,visited,dfsTracker)) {
                    return true;
                }
            }
            else if(visited[nbr] == true && dfsTracker[nbr] == true) {
                return true;
            }
        }

        dfsTracker[src] = false;

        return false;
    }

    bool detectCycleDFS_D(int n) {
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsTracker;

        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                if(dfsCycle_D(i,visited,dfsTracker)) return true;
            }
        }
        return false;
    }

};



int main() {

    int V;
    cout<<"Enter The Nodes : ";
    cin>>V;

    vector<pair<int,int>> edges;
    cout<<"Enter Data : ";
    for(int i=0;i<V;i++) {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    Graph g;
    for(auto e : edges) {
        g.addEdge(e.first,e.second,1);
    }


    if(g.detectCycleDFS_D(V)) {
        cout<<"Cycle Detected -> DFS!"<<endl;
    }
    else{
        cout<<"No Cycle Found -> DFS"<<endl;
    }

    return 0;

}