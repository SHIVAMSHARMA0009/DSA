/* Inorder to BST conversion */

#include<bits/stdc++.h>
using namespace std;

class Node {

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

Node* buidlBST(vector<int>&inorder,int start,int end) {

    if(start > end) return NULL;

    int mid = start + (end-start)/2;
    int val = inorder[mid];

    Node* root = new Node(val);

    root->left = buidlBST(inorder,start,mid-1);
    root->right = buidlBST(inorder,mid+1,end);

    return root;
    
}

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


int main() {

    int n;
    cout<<"Enter Size : ";
    cin>>n;

    vector<int>inorder(n);
    cout<<"Enter Value in  Sorted Order : ";
    for(int i=0;i<n;i++) {
        cin>>inorder[i];
    }

    Node* root = buidlBST(inorder,0,n-1);

    cout<<"The Tree : "<<endl;
    levelOrderTraveral(root);

    return 0;

}