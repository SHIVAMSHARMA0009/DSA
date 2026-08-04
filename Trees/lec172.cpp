/* Basic Implementation/creation of Tree */
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

    if(data == -1) {
        return NULL;
    }
    else{
        Node* root = new Node(data);

        root->left = buildTree();     // 1st case solve rest recursion will see
        root->right = buildTree();
    }
}


// NLR -> pre-order

void preOrderTraversal(Node* root) {
    
    // base case
    if(root == NULL) {
        return;
    }

    // just solve 1 case -> rest recursion will see

    cout<<root->data<<" ";                   // printing N
    preOrderTraversal(root->left);           // printing L
    preOrderTraversal(root->right);          // priting R

}

// LNR -> in-order
void inOrderTraversal(Node* root) {
    
    // base case
    if(root == NULL) {
        return;
    }

    // just solve 1 case -> rest recursion will see

    inOrderTraversal(root->left);           // printing L
    cout<<root->data<<" ";                  // printing N
    inOrderTraversal(root->right);          // priting R

}


// LRN -> post-order
void postOrderTraversal(Node* root) {
    
    // base case
    if(root == NULL) {
        return;
    }

    // just solve 1 case  -> rest recursion will see

    postOrderTraversal(root->left);           // printing L
    postOrderTraversal(root->right);          // priting R
    cout<<root->data<<" ";                    // printing N

}


// Level-order traversal : means iterate level 0 -> level 1 -> level 2 ---- so on

// use queue  -> whenever parent node will move out -> child node will be inserted
void levelOrderTraversal(Node* root) {

    if(root == NULL) {
        return;
    }

    queue<Node*> q;                            // maintain initial state
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front == NULL){          // printed all node of current level -> go to next line
            cout<<endl;
            if(!q.empty()){                       // if queue is empty then don't insert NULL -> infinite loop
                q.push(NULL);
            }
        }

        else{
            cout<<front->data<<" ";

            if(front->left != NULL) {
                q.push(front->left);
            }

            if(front->right != NULL) {
                q.push(front->right);
            }
        }

    }
}


int main() {

    // 10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1
    Node* root = buildTree();
    cout<<endl;
    cout<<"Printing Preorder Traversal : ";
    preOrderTraversal(root);

    cout<<endl;
    cout<<"Printing Inorder Traversal : ";
    inOrderTraversal(root);

    cout<<endl;
    cout<<"Printing Postorder Traversal : ";
    postOrderTraversal(root);

    cout<<endl;
    cout<<"Printing Level-Order Traversal : "<<endl;
    levelOrderTraversal(root);

    return 0;
}

