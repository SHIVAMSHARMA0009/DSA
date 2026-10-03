/* SHORTEST PATH */

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int,vector<int>>adjList;

    void addEdges(int u,int v,bool direction) {
        if(direction == 0) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }


    //SHOREST PATH (UNDIRECTED)
    void shortestPath(int src,int dest) {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        queue<int>q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto nbr : adjList[front]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = front;
                }
            }
        }

        // now including path
        vector<int>path;
        int node = dest;
        while(node != -1) {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(),path.end());

        cout<<"Printing Path : ";
        for(auto i : path) {
            cout<<i<<" -> ";
        }
        cout<<endl;

    }

};


int main() {

    Graph g;
    g.addEdges(0,1,0);
    g.addEdges(1,2,0);
    g.addEdges(2,3,0);
    g.addEdges(2,4,0);
    g.addEdges(4,5,0);
    g.addEdges(5,3,0);

    int src = 0;
    int dest = 3;

    g.shortestPath(src,dest);

    return 0;
    
}