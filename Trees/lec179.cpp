/* we are given a tree we have to print it diagonally */

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree() {

    int val;
    cin >> val;

    if(val < 1) {
        return NULL;
    }

    Node* root = new Node(val);

    root->left = buildtree();
    root->right = buildtree();

    return root;

}


// approach 1 : T.C : O(nlogk)    S.C : O(n+h)
void solve(Node* root,map<int,vector<int>>&mp,int d) {

    if(root == NULL) return;

    mp[d].push_back(root->data);

    solve(root->left,mp,d+1);

    solve(root->right,mp,d);
    
}

vector<int> diagonal(Node* root) {

    if(root == NULL) return {};

    map<int,vector<int>>mp;

    solve(root,mp,0);

    vector<int>ans;

    for(auto it : mp) {
        for(auto val : it.second) {
            ans.push_back(val);
        }
    }

    return ans;

}


// approach 2 :  T.C : O(n)     S.C : O(n)
vector<int> diagonal1(Node* root) {

    vector<int>ans;
    if(root == NULL) return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        while(temp) {
            ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            temp = temp->right;
        }
    }

    return ans;
}

int main() {

    cout<<"Enter Data : ";
    Node* root = buildtree();

    vector<int>ans = diagonal1(root);

    cout<<"The traversal : ";
    for(auto val : ans) {
        cout<<val<<" ";
    }

    return 0;

}