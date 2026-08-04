/* we are given binary tree -> we have to check -> convert it into sum tree */

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

void levelOrderTraversal(Node* root) {

    if(root == NULL) return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {

        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            if(!q.empty()) {
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

int convertIntoSum(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftsum = convertIntoSum(root->left);
    int rightsum = convertIntoSum(root->right);

    root->data = leftsum + root->data + rightsum;

    return root->data;

}


int main() {


    Node* root = buildTree();

    convertIntoSum(root);

    cout<<"The Tree After Submission : "<<endl;
    levelOrderTraversal(root);

    return 0;
}