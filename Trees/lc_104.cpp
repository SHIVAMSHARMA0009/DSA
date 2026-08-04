/* Given the root of a binary tree, return its maximum depth.
   A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. 
*/

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right =NULL;
    }
};

Node*  buildTree() {

    int val;
    cin>>val;

    if(val < -100 || val > 100) {
        return NULL;
    }

    else{
        Node* root = new Node(val);

        root->left = buildTree();
        root->right = buildTree();
    }

}

int maxDepth(Node* root) {

    if(root == NULL) return 0;

    int left_depth = maxDepth(root->left) + 1;      // number of nodes at left sub tree + root node
    int right_depth = maxDepth(root->right) + 1;    // number of nodes at right sub tree + root node

    return max(left_depth,right_depth);      // returns maximum depth

}

int main() {

    Node* root = buildTree();

    cout<<"Maximum Depth : "<<maxDepth(root);

    return 0;
}