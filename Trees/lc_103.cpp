/* we are given binary tree , return its zig-zag traversal    || ZIGZAG : L->R then R->L then L->R ...... */  

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

Node* buildTree() {

    int val;
    cin>>val;

    if(val == -1) return NULL;

    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;

}

// T.C : O(n)    || S.C : O(n)
vector<vector<int>> zigzag(Node* root) {

    vector<vector<int>> ans;
    if(root == NULL) return ans;

    int LtoRdir = true;
    queue<Node*> q;                // push root into queue
    q.push(root);

    while(!q.empty()) {

        int n = q.size();       
        vector<int>temp(n);          // taking vector size equal to no. of child of root that is already pushed to queue

        for(int i=0;i<n;i++) {
            Node* front = q.front();
            q.pop();

            int index = LtoRdir ? i : n - i - 1;          // if L -> R start with 0 , if R -> L then from index of vector
            temp[index] = front->data;

            if(front->left) q.push(front->left);          // push the children of current node into queue
            if(front->right) q.push(front->right);
        }

        LtoRdir = !LtoRdir;      // after completing one level change the direction for next level
        ans.push_back(temp);
    }
    return ans;
}

int main() {

    cout<<"Enter Tree Data : ";
    Node* root = buildTree();

    vector<vector<int>>ans = zigzag(root);

    cout<<"The Zig Zag : ";
    for(auto arr : ans) {
        for(auto val : arr) {
            cout<<val<<" ";
        }
    }

    return 0;
}