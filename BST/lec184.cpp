/* creation of Binary Search Tree */

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

// Traversal

void levelOrderTraveral(Node* root) {    // level 0 -> level 1 -> level 2 -> ------

    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<<front->data<<" ";

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

        }
    }

}

void preOrderTraversal(Node* &root) {    // NLR

    if(root == NULL) return; 

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* &root) {   // LRN

    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}

void inOrderTraversal(Node* &root) {   // LNR

    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
    
}


// creation of BST
Node* buildBST(Node* root,int data) {

    if(root == NULL) {                     // if root  is null -> make node of value and return
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = buildBST(root->left,data);          // if value is less than root node -> insert it  to left
    }
    else{
        root->right = buildBST(root->right,data);              // otherwise left
    }

    return root;
}

Node* takeInput(Node* &root) {

    int data;
    cin>>data;

    while(data  != -1) {
        root = buildBST(root,data);    
        cin>>data;
    }

}


int main () {

    Node* root = NULL;
    cout<<"Enter The Input : ";
    takeInput(root);

    cout<<endl;
    cout<<"Printing BST : "<<endl;
    levelOrderTraveral(root);
    cout<<endl;

    cout<<"Preorder Traversal : ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal : ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Preorder Traversal : ";
    inOrderTraversal(root);
    
    return 0;
    
}

