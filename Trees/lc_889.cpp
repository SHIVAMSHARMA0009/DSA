/* we are given two vector preorder & postorder -> build binary tree */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left =NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node*  root) {

    if(root == NULL) {
        return;
    }

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

            if(front->left !=  NULL) {
                q.push(front->left);
            }

            if(front->right !=  NULL) {
                q.push(front->right);
            }
        }
    }

}

Node* construct(vector<int>&preorder,vector<int>&postorder,int prestart,int poststart,int preend) {

    if(prestart > preend) {
        return NULL;
    }

    Node* root = new Node(preorder[prestart]);         // the root node
    
    if(prestart == preend) {
        return root;
    }

    int nextNode = preorder[prestart+1];           // NLR : preorder me root ke next wala hi left-subtree ka root hoga

    int j = poststart;                            // LRN : find index of rootnode of leftsubtree in postorder
    while(postorder[j] != nextNode) {
        j++;
    }

    int num_count = j - poststart + 1;          // calculate no. of nodes starting to index   -> kyuki itne hi node root(main node) ke leftsubtree me honge

    root->left = construct(preorder,postorder,prestart+1,poststart,prestart+num_count);   // now join root->left to that portion of preorder vector
    root->right = construct(preorder,postorder,prestart+num_count+1,j+1,preend);        // now join root->left to that portion of preorder vector

    return root;
    
}



int main () {

    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,10};

    Node* root = construct(preorder,postorder,0,0,preorder.size()-1);

    levelOrderTraversal(root);

    return 0;

}