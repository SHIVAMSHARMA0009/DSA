/* we are given the a binary tree -> return its diameter means we have to send the longest path in binary tree */

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
        right = NULL;
    }
};

// return root node of tree
Node* buildTree() {

    int data;
    cin>>data;

    if(data < -100 || data > 100) {
        return NULL;
    }
    else{
        Node* root = new Node(data);

        root->left = buildTree();     // 1st case solve rest recursion will see
        root->right = buildTree();
    }
}

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    int left_depth = maxDepth(root->left) + 1;
    int right_depth = maxDepth(root->right) + 1;
    return max(left_depth,right_depth);
}

int diameterOfBinaryTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int option1 = maxDepth(root->left) + maxDepth(root->right);    // includes the root node
    int option2 = diameterOfBinaryTree(root->left);                // left binary tree
    int option3 = diameterOfBinaryTree(root->right);               // right binary tree

    return max({option1,option2,option3});
}

int main() {

    Node* root = buildTree();

    cout<<"The Diameter : "<<diameterOfBinaryTree(root);

    return 0;
}