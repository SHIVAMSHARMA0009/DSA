/* check the given tree is complete binary tree or not */

/* APPROACH : level-order traversal => if there exist any element/node after null , then tree will be not a complete binary tree */


#include<bits/stdc++.h>
using namespace std;


class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left =NULL;
        this->right = NULL;
    }
};

Node* builTree() {
    
    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    root->left = builTree();
    root->right = builTree();

    return root;

}

bool checkCBT(Node* root) {

    if(root == NULL) return true;

    queue<Node*>q;                     // pushed the root node
    q.push(root);

    bool nullFound = false;

    while(!q.empty()) {

        Node* front = q.front();           // pop the front of queue
        q.pop();

        if(front == NULL) {
            nullFound = true;                   // if we found null , then there should be no next node
        }
        else{
            if(nullFound) return false;        // if null is already traced , but still we have node in the tree -> tree is not CBT

            q.push(front->left);          //  otherwise push the child of front node in the queue
            q.push(front->right);
        }
    }

    return true;

}


int main () {

    cout<<"Enter Tree Node : ";
    Node* root = builTree();

    cout<<"Is Tree a Complete Binary Tree : "<<checkCBT(root)<<endl;

    return 0;

}