/* Topological Sort */
#include<bits/stdc++.h>
using namespace std;

class  Graph {

    public:

    unordered_map<int,vector<int>> adjList;
    void addEdges(int u,int v) {
        // u -> v
        adjList[u].push_back(v);
    }


    // BFS
    void topoSortBFS(int n, vector<int>& ans) {

        vector<int> inDegree(n,0);
        queue<int>q;

        // calculate inDegree 
        for(auto& u : adjList) {
            for(auto v : u.second) {
                inDegree[v]++;
            }
        }

        // now  push all the nodes into queue with inDegree == 0
        for(int i=0; i<n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        // main-logic
        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();

            //include into ans
            ans.push_back(frontNode);

            //update the neighbours inDegree
            for(auto nbr : adjList[frontNode]) {
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

    }

    

    // DFS
    void solveUsingDFS(int src,unordered_map<int,bool>&visited,vector<int>&ans) {
        visited[src] = true;
        for(auto nbr : adjList[src]) {
            if(!visited[nbr]) {
                solveUsingDFS(nbr,visited,ans);
            }
        }
        ans.push_back(src);

    }
    vector<int> topoSortDFS(int V) {
        vector<int>ans;
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                solveUsingDFS(i,visited,ans);
            } 
        }
        return ans;
    }

};


int main() {

    Graph g;

    int V,E;
    cout<<"Enter The Nodes & Edges : ";
    cin>>V>>E;

    vector<pair<int,int>>edges;
    cout<<"Enter Node Data : ";
    for(int i=0;i<E;i++) {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    for(auto e : edges) {
        g.addEdges(e.first,e.second);
    }

    vector<int> order;
    g.topoSortBFS(V, order);

    cout<<"The Order (BFS) : ";
    for(auto ele : order) {
        cout<<ele<<" ";
    }
    cout<<endl;

    vector<int> order1;
    g.topoSortBFS(V, order1);
    cout<<"The Order (DFS) : ";
    for(auto ele : order1) {
        cout<<ele<<" ";
    }

    return 0;

}