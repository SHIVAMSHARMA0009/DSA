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

    bool bfsCycle(int src, unordered_map<int,bool>& visited) {

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

    bool detectCycle(int n) {
        unordered_map<int,bool>visited;

        for(int i=0;i<n;i++) {              // graph may have multiple compenents
            if(!visited[i]) {
                if(bfsCycle(i,visited)) {
                    return true;
                }
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
        g.addEdge(e.first,e.second,0);
    }

    if(g.detectCycle(V)) {
        cout<<"Cycle Detected!"<<endl;
    }
    else{
        cout<<"No Cycle Found"<<endl;
    }

    return 0;

}