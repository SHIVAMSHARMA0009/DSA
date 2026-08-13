/* we are given a tree -> check tree is heap or not */

/* APPROACH :  1. it should be complete binary tree 
               2. it should satisfies max_heap
*/

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

    int data;
    cin>>data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;

}

bool checkCBT(Node* root) {

    queue<Node*>q;
    q.push(root);

    bool nullFound = false;

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            nullFound = true;
        }
        else{
            if(nullFound) return false;

            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}

bool checkNode(Node* root) {

    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;

    bool leftAns = checkNode(root->left);                           // left sub tree ka ans
    bool rightAns = checkNode(root->right);                         // right sub tree ka ans

    bool leftCheck = true;
    bool rightCheck = true;

    if(root->left && root->data < root->left->data) leftCheck = false;            // left node badi hai ya choti
    if(root->right && root->data < root->right->data) rightCheck = false;         // right node badi hai ya choti

    bool currNodeAns = leftCheck && rightCheck;                                  // dono child node ki wajah se parent node ka ans
    
    if(currNodeAns && leftAns && rightAns) return true;           // agr current node aur left sub-tree and right sub-tree dono thik hai toh true return krdo

    return false;
}

bool checkHeap(Node* root) {

    if(root == NULL) return true;

    bool CBTAns = checkCBT(root);
    if(!CBTAns) return false;

    bool NodeAns = checkNode(root);

    return CBTAns && NodeAns;

}

int main() {

    cout<<"Enter The tree Node : ";
    Node* root = buildTree();

    cout<<"Is tree a Heap : "<<checkHeap(root);

    return 0;
}