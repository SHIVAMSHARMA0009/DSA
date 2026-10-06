/* we are given an integer numCourses and two interger vector one is prerequities and other is query */
/* we have to return the boolean vector on the basis -> are we able of complete the all the courses through given query */
/* prerequities means [u,v] => if we want to take v first we have to take u */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    vector<int> inDegree;
    vector<unordered_set<int>> reachable;

    vector<bool> solve(int numCourses, vector<vector<int>>& queries, vector<bool>& ans) {
        queue<int> q;
        int count = 0;

        for (int i = 0; i < numCourses; i++) {   // push all the node with inDegree into queue
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int frontNode = q.front();    // pull out the front node
            q.pop();
            count++;

            for (auto nbr : adjList[frontNode]) {
                // direct parent
                reachable[nbr].insert(frontNode);
                // indirect parents
                for (auto anc : reachable[frontNode]) {
                    reachable[nbr].insert(anc);
                }

                inDegree[nbr]--;                    // as one parent node is pulled out -> decrease its neighbours inDegree
                if (inDegree[nbr] == 0) {           // if any nodes inDegree becomes 0 means there is no dependency for this node now
                    q.push(nbr);                   // then push it to queue
                }
            }
        }

        if (count != numCourses) return ans;     // if count is not equal to numCourses means all courses are not possible to take due to dependency which created the loop

        int i = 0;                             // ohterwise , 
        for (auto& a : queries) {    
            int u = a[0], v = a[1];            // tarverse each query -> if its dependency found -> update the boolean value  
            if (reachable[v].count(u)) {
                ans[i] = true;
            }
            i++;
        }

        return ans;           
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = queries.size();
        inDegree = vector<int>(numCourses, 0);
        reachable = vector<unordered_set<int>>(numCourses);
        vector<bool> ans(n, false);

        for (auto& a : prerequisites) {     // list formation
            int u = a[0];
            int v = a[1];
            adjList[u].push_back(v);
            inDegree[v]++;                 // count the inDegree as well
        }

        return solve(numCourses, queries, ans);
    }
};

int main() {
  
    int numCourses, p, q;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    cout << "Enter number of prerequisites: ";
    cin >> p;
    vector<vector<int>> prerequisites(p, vector<int>(2));
    cout << "Enter prerequisites : ";
    for (int i = 0; i < p; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    cout << "Enter number of queries: ";
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    cout << "Enter queries : ";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;
    vector<bool> ans = sol.checkIfPrerequisite(numCourses, prerequisites, queries);

    cout << "Query Results : ";
    for (int i = 0; i < q; i++) {
        cout <<(ans[i] ? "True" : "False")<<" ";
    }

    return 0;
}
