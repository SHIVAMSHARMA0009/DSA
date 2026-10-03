/* SHORTEST PATH DIRCTED GRAPH */
/* SHORTEST PATH */

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdges(int u,int v,int wt, bool direction) {
        if(direction == 0) {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    }


    void topoSortDfs(int src, unordered_map<int,bool>&visited, stack<int>&ans) {
        visited[src] = true;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr.first]) {
                topoSortDfs(nbr.first,visited,ans);
            }
        }
        ans.push(src);
    }

    void shortestPathDfs(int src) {

        stack<int> topOrder;
        unordered_map<int,bool>visited;

        topoSortDfs(src,visited,topOrder);
        
        // now topological stack ready
        int n = topOrder.size();
        vector<int> dist(n,INT_MAX);

        // initial  state
        src = topOrder.top();
        topOrder.pop();
        dist[src] = 0;

        // now update the minimum distance of neighbours
        for(auto nbr : adjList[src]) {

            int node = nbr.first;
            int weightDistance = nbr.second;

            if(dist[src] + weightDistance < dist[node]) {
                dist[node] = dist[src] + weightDistance;
            }
        }

        // main logic
        while(!topOrder.empty()) {

            int frontNode = topOrder.top();
            topOrder.pop();

            for(auto nbr : adjList[frontNode]) {

                int node = nbr.first;
                int weightDistance = nbr.second;
                if(dist[frontNode] + weightDistance < dist[node]) {
                    dist[node] = dist[frontNode] + weightDistance;
                }
            }
        }

        cout<<"Distance Array : ";
        for(auto i : dist) {
            cout<<i<<" ";
        }
        cout<<endl;

    }
};


int main() {

    Graph g;
    g.addEdges(0,1,5,1);
    g.addEdges(0,2,13,1);
    g.addEdges(0,4,3,1);
    g.addEdges(1,2,7,1);
    g.addEdges(1,4,1,1);
    g.addEdges(4,3,6,1);
    g.addEdges(3,2,2,1);
    
    g.shortestPathDfs(0);

    return 0;
    
}