/* we have to return the (no. of nodes) largest BST in a given BINARY TREE */

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

class NodeData{       // what are the information a node should contain for valid BST
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData() {

    }

    NodeData(int size,int max,int min,bool valid) {
        this->size = size;
        this->minVal = min;
        this->maxVal = max;
        this->validBST = valid;
    }

};

// return root node of tree
Node* buildTree() {

    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    root->left = buildTree();     // 1st case solve rest recursion will see
    root->right = buildTree();

    return root;

}


NodeData findLargestBST(Node* root,int &ans) {

    if(root == NULL) {
        NodeData temp(0,INT_MIN,INT_MAX,true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left,ans);
    NodeData rightAns = findLargestBST(root->right,ans);

    // checking start here
    NodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.minVal = min(root->data,leftAns.minVal);
    currNodeAns.maxVal = max(root->data,rightAns.maxVal);
    
    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)) {
        currNodeAns.validBST = true;
    }
    else{
        currNodeAns.validBST = false;
    }

    if(currNodeAns.validBST) {
        ans = max(ans,currNodeAns.size);
    }

    return currNodeAns;

}

int main () {

    cout<<"Enter Tree Data : ";
    Node* root = buildTree();

    int ans = 0;

    findLargestBST(root,ans);

    cout<<"The Size of largest BST : "<<ans<<endl;

    return 0;

}