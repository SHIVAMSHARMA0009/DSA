/* we have to delete the given node from BST */

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

Node* buidlBST(Node* &root,int data) {

    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = buidlBST(root->left,data);
    }
    else{
        root->right = buidlBST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root) {

    int data;
    cin>>data;

    while(data != -1) {
        root = buidlBST(root,data);
        cin>>data;
    }
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

/* CASE 1 : LEAF NODE means it will not have left and right child  - so after deletion nothing is attached so return NULL */
/* CASE 2 : one child of node is not present -> delete node and return the one child */
/* CASE 3 : both Node is present -> replacing data with inorder predecessor/successor then delete the node of which data has been used */

int maxVal(Node* root) {

    if(root == NULL) return -1;

    while(root->right) root = root->right;

    return root->data;

}

Node* deleteNodeInBst(Node* root,int target) {

    if(root == NULL) return root;

    if(root->data == target) {

        // to delete temp there will exist above 4 cases
        if(root->left == NULL && root->right == NULL) {     // case 1  : leaf node 
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL) {   // case 2 : left child nhi hai
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL) {       // case 2 : right child nhi hai
            Node* child = root->left;
            delete root;
            return child;
        }
        else{                                                         // case 4 : dono child hai
            int inorderPre = maxVal(root->left);                        // so pehle inorder predecessor nikalo
            root->data = inorderPre;                                 // data ko replace karo
            root->left = deleteNodeInBst(root->left,inorderPre);    // aur inorder predecessor ko delete karo
            return root;
        }

    }

    else if(root->data > target) {
        root->left = deleteNodeInBst(root->left,target);      // jo bhi return hoga uska link maintain kro
    }
    else{
        root->right = deleteNodeInBst(root->right,target);    
    }

    return root;

}


int main() {

    Node* root = NULL;
    cout<<"Enter Node Value : ";
    takeInput(root);
    cout<<endl;

    cout<<"Tree Before Deletion : "<<endl;
    levelOrderTraveral(root);
    cout<<endl;

    int target;
    cout<<"Enter Node To Delete : ";
    cin>>target;

    root = deleteNodeInBst(root,target);
    cout<<endl;

    cout<<"Tree after Deletion : "<<endl;
    levelOrderTraveral(root);

    return 0;


}