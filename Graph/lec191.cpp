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

    // BFS Approach (UNDIRECTED)
    bool bfsCycle_U(int src, unordered_map<int,bool>& visited) {

        queue<int>q;
        unordered_map<int,int>parent;

        q.push(src);                     // push the source into the queue
        visited[src] = true;             //mark it as visited
        parent[src] = -1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto nbr : adjList[curr]) {         // its time for currnode neighbours
                if(!visited[nbr]) {           // if neigbbours are not visited
                    q.push(nbr);              // push into queue
                    visited[nbr] = true;      // mark neighbours as visited
                    parent[nbr] = curr;      // and mark their current
                }
                else if(visited[nbr] == true && nbr != parent[curr]) {    // suppose if neighbour is already visited and neighbour is not parent of current node
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycleBFS_U(int n) {
        unordered_map<int,bool>visited;

        for(int i=0;i<n;i++) {              // graph may have multiple compenents
            if(!visited[i]) {
                if(bfsCycle_U(i,visited)) {
                    return true;
                }
            }
        }
        return false;
    }


    // DFS Approach (UNDIRECTED)
    bool dfsCycle_U(int src,int parent, unordered_map<int,bool>& visited) {
        visited[src] = true;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                if(dfsCycle_U(nbr,src,visited)) return true;
            }
            else if(visited[true] && nbr != parent) {
                return true;
            }
        }
        return false;
    }

    bool detectCycleDFS_U(int n) {
        unordered_map<int,bool>visited;

        for(int i=0;i<n;i++) {              // graph may have multiple compenents
            if(!visited[i]) {
                if(dfsCycle_U(i,-1,visited)) {
                    return true;
                }
            }
        }
        return false;
    }



    // DFS Approach (DIRECTED)

    bool  dfsCycle_D(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsTracker) {
        visited[src] = true;
        dfsTracker[src] = true;

        for(auto nbr : adjList[src]) {
            if(dfsCycle_D(nbr,visited,dfsTracker)) {
                return true;
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

    int V,E;
    cout<<"Enter The Nodes and Edges : ";
    cin>>V>>E;

    vector<pair<int,int>> edges;
    cout<<"Enter Data : ";
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    Graph g;
    for(auto e : edges) {
        g.addEdge(e.first,e.second,1);
    }

    // if(g.detectCycleBFS_U(V)) {
    //     cout<<"Cycle Detected -> BFS!"<<endl;
    // }
    // else{
    //     cout<<"No Cycle Found -> BFS"<<endl;
    // }


    // if(g.detectCycleDFS_U(V)) {
    //     cout<<"Cycle Detected -> DFS!"<<endl;
    // }
    // else{
    //     cout<<"No Cycle Found -> DFS"<<endl;
    // }

    if(g.detectCycleDFS_D(V)) {
        cout<<"Cycle Detected -> BFS!"<<endl;
    }
    else{
        cout<<"No Cycle Found -> BFS"<<endl;
    }

    return 0;

}