/* BellmanForAlgo (SHORTEST PATH ALGORITHM) */ 

#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdges(int u,int v,int wt,bool direction) {
        if(direction == 0) {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        else{
            adjList[u].push_back({v,wt});
        }
    }

    void bellmanForAlgo(int src,int n) {
        vector<int>dist(n,INT_MAX);

        dist[src] = 0;

        // n-1 relaxation step ko chalao
        for(int i=0;i<n-1;i++) {

            for(auto a : adjList) {
                for(auto b : a.second) {

                    // a -> u
                    // a.second -> b (neighbours of a) in pairs
                    // b.first -> v
                    // b.second -> weight

                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }

        }

        bool negativeCyclePresent = false;
        for(auto a : adjList) {
            for(auto b : a.second) {

                // a -> u
                // a.second -> b (neighbours of a) in pairs
                // b.first -> v
                // b.second -> weight

                int u = a.first;
                int v = b.first;
                int wt = b.second;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    negativeCyclePresent = true;
                    break;
                }
            }
        }

        if(negativeCyclePresent == true) {
            cout <<  "Negative Cycle Present !!"<<endl;
        }
        else{
            
            cout<<"No Negative Cycle !!"<<endl;

            cout<<"Printing Shortest Distance : ";
            for(int i=0;i<n;i++) {
                cout<<dist[i]<<" ";
            }
        }

    }

};

int main() {
    
    Graph g;
    g.addEdges(0,1,-1,1);
    g.addEdges(1,4,2,1);
    g.addEdges(0,2,4,1);
    g.addEdges(3,2,5,1);
    g.addEdges(4,3,-3,1);
    g.addEdges(1,2,3,1);
    g.addEdges(1,3,2,1);
    g.addEdges(3,1,1,1);

    g.bellmanForAlgo(0,5);

    return 0;
    
}
