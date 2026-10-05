/* DIJKSTRA ALGORITHM (SHORTEST PATH ALGORITHM) ->  GREEDY APPROACH */

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

    void shortestDistanceDijkstra(int src,int n) {
        vector<int>dist(n+1,INT_MAX);
        set<pair<int,int>>st;

        // initial  state
        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()) {
            auto topElement = *(st.begin());
            int topNodeDistance = topElement.first;
            int topNode = topElement.second;

            //pop this node
            st.erase(st.begin());

            // visit neighbouring node
            for(auto nbr: adjList[topNode]) {
                //  nbr is pair
                // nbr = {a,b} => a = node -> b = weight;
                int nbrNode = nbr.first;
                int nbrDistance = nbr.second;
                if(dist[topNode] + nbrDistance < dist[nbrNode]) {
                    // update distance array and update set
                    auto result = st.find({dist[nbrNode],nbrNode});
                    if(result != st.end()) {
                        st.erase(result);
                    }
                    dist[nbrNode] = dist[topNode] + nbrDistance;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }

        cout<<"Printing Minimum Distance : ";
        for(int i=0;i<n;i++) {
            cout<<dist[i]<<" ";
        }

    }

};

int main() {
    
    Graph g;
    g.addEdges(0,5,9,1);
    g.addEdges(0,3,6,1);
    g.addEdges(5,4,2,1);
    g.addEdges(4,3,11,1);
    g.addEdges(5,1,14,1);
    g.addEdges(4,1,9,1);
    g.addEdges(4,2,10,1);
    g.addEdges(3,2,15,1);
    g.addEdges(2,1,7,1);

    g.shortestDistanceDijkstra(0,6);

    return 0;
    
}
