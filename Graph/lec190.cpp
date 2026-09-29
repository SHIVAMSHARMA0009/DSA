/* Implementation of Graph */

#include<bits/stdc++.h>
using namespace std;

class Graph{                                     // unweighted Graph
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

    void print() {
        for(auto i : adjList) {
            cout<<i.first<<" : ";
            cout<<"{";
            for(auto j : i.second) {
                cout<<j<<" , ";
            }
            cout<<"}"<<endl;
        }
    }
};


class WGraph{                                 // weighted Graph
    public:
    unordered_map<int,vector<pair<int,int>>> adjList;
    
    void addEdge(int u, int v, int wt, bool direction) {
        if(direction == 1) {
            // directed edge
            // u -> v
            // u -> (v,wt)
            adjList[u].push_back(make_pair(v,wt));
        }
        else{
            // undirected edge
            // u -- v
            // u -> (v,wt) == v -> (u,wt)
            adjList[u].push_back(make_pair(v,wt));\
            adjList[v].push_back(make_pair(u,wt));
        }
    }

    void print() {
        for(auto i : adjList) {
            cout<<i.first<<" : ";
            cout<<"{";
            for(auto j : i.second) {
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }
            cout<<"}"<<endl;
        }
    }
};

int main() {

    Graph g;
    WGraph wg;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);

    g.print();
    cout<<endl;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);

    g.print();
    cout<<endl;

    wg.addEdge(0,1,10,1);
    wg.addEdge(1,2,20,1);
    wg.addEdge(2,3,30,1);
    wg.addEdge(3,4,40,1);

    wg.print();
    cout<<endl;

    return 0;

}