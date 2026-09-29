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


    // entire BFS Logic
    void bfsTraversal(int src) {
        queue<int>q;
        unordered_map<int,bool>visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            cout<<front<<", ";
            for(auto nbr : adjList[front]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }



    // entire DFS logic 
    void dfsHelper(int src,unordered_map<int,bool>& visited) {

        // print and mark true after immediate call
        cout<<src<<", ";
        visited[src] = true;

        for(auto nbr : adjList[src]) {
            // if neighbour are not visited -> then call dfs for them
            if(!visited[nbr]) {
                dfsHelper(nbr,visited);
            }
        }
    }

    void dfsTraversal(int src,int n) {
        unordered_map<int,bool>visited;
        for(int src=0;src<n;src++) {     //  to handle disconnected components
            if(!visited[src]) {
                dfsHelper(src,visited);
            }
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


    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,8,1);
    g.addEdge(8,4,1);
    g.addEdge(4,5,1);
    g.addEdge(4,7,1);
    g.addEdge(5,6,1);
    g.addEdge(7,6,1);
    g.print();
    cout<<endl;

    cout<<"BFS : ";
    g.bfsTraversal(0);
    cout<<endl;

    cout<<"DFS : ";
    g.dfsTraversal(0,10);

    return 0;

}