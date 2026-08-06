/* validate BST :  we have to check whether the given tree is BST or not */
/* approach is very simple if current node falls under the range means left (-infinite,parent_node->value)  & right (parent_node->value,infinite) */

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

bool solve(Node* root,long long lowerbound,long long upperbound) {

    if(root == NULL) return true;

    if(root->data > lowerbound && root->data < upperbound) {          // if condition satisfies and root lie in range

        bool leftAns = solve(root->left,lowerbound,root->data);        // check for left subtree
        bool rightAns = solve(root->right,root->data,upperbound);      // check for right subtree
 
        return leftAns && rightAns;
    }

    return false;

}

bool check_BST(Node* root) {

    long long lowerbound = -2147483649;
    long long upperbound =  2147483648;

    bool ans = solve(root,lowerbound,upperbound);

    return ans;
    
}


Node* buildTree() {

    int data;
    cin>>data;

    Node* root;

    if(data == -1) {
        return NULL;
    }
    else{
        root = new Node(data);
        root->left = buildTree();
        root->right = buildTree();
    }

    return root;
}



int main() {

    cout<<"Enter The Tree Value : ";
    Node* root = buildTree();

    cout<<"Is BST : "<<check_BST(root);

    return 0;

    
}