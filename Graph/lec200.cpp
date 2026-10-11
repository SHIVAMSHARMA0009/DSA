/* KosaRaju Algorithm */
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

    void topoSortdfs(stack<int>&s, int node, unordered_map<int,bool>&vis) {
        vis[node] = true;
        for(auto nbr : adjList[node]) {
            if(!vis[nbr]) {
                topoSortdfs(s, nbr, vis);
            }
        }

        s.push(node);
    }

    void dfs(int src, unordered_map<int,bool>&vis, unordered_map<int,list<int>>&adjNew) {
        vis[src] = true;

        cout<<src<<" - ";
        for(auto nbr : adjNew[src]) {
            if(!vis[nbr]) {
                dfs(nbr, vis, adjNew);
            }
        }
    }

    int countSCC(int n) {
        // find toto ordering
        stack<int>s;
        unordered_map<int,bool> vis;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoSortdfs(s, i, vis);
            }
        }

        // now we ready stack

        // stack 2 : reverse all edges;
        unordered_map<int,list<int>> adjNew;
        for(auto i : adjList) {
            for(auto j : i.second){
                int u = i.first;
                int v = j;
                adjNew[v].push_back(u);
            }
        }

        //traversal
        int count = 0;
        unordered_map<int,bool>visited;
        while(!s.empty()) {
            int src = s.top();
            s.pop();

            if(!visited[src]) {
                cout<<"SCC : ";
                dfs(src,visited,adjNew);
                cout<<endl;
                count++;
            }
        }
        return count;
    }

};

int main() {

    Graph g;
    g.addEdges(0,3,1);
    g.addEdges(3,2,1);
    g.addEdges(2,1,1);
    g.addEdges(1,0,1);
    g.addEdges(2,4,1);
    g.addEdges(4,5,1);
    g.addEdges(5,6,1);
    g.addEdges(6,4,1);
    g.addEdges(6,7,1);
    int n = 8;
    g.printAdjList(n);

    
    int sccCount = g.countSCC(n);
    cout<<"The Disconnected Component : "<<sccCount<<endl;

    return 0;
}