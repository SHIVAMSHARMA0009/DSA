/* we are given a tree we have to check -> tree is sum tree of not means sum of nodes of left-subtree and right-subtree should be equal to parent value*/

/* we are given a tree  -> check whether tree is sum tree or not */

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

Node* buildTree() {

    int val;
    cin>>val;

    if(val == -1) {
        return NULL;
    }
    else{
        Node* root = new Node(val);

        root->left = buildTree();
        root->right = buildTree();

    }

}

int find_sum(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftsum = find_sum(root->left);
    int rightsum = find_sum(root->right);

    return leftsum + rightsum + root->data;

}

bool check_sum(Node* root) {

    if(root == NULL) {
        return true;
    }

    if(root->left == NULL && root->right == NULL) {
        return true;
    }

    int leftTreeSum = find_sum(root->left);
    int rightTreeSum = find_sum(root->right);

    if(leftTreeSum + rightTreeSum != root->data) return false;

    bool leftans = check_sum(root->left);
    bool  rightans = check_sum(root->right);

    if(leftans == true && rightans == true) {
        return true;
    }

    return false;

}

int main() {

    Node* root = buildTree();

    cout<<"Is Sum tree ? "<<check_sum(root);

    return 0;

}