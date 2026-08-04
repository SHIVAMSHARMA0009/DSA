/* we have to build the binary tree from in-order & post-order traversal */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right =NULL;
    }
};

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

int get_index(vector<int>inorder,int element) {

    for(int i=0;i<inorder.size();i++) {
        if(inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int>inorder,vector<int>postOrder,int &postOrderIndex,int inOrderStart,int inOrderEnd) {

    if(postOrderIndex < 0) {                       // agr postorder wali array khatam ho gyi toh null return krdo
        return NULL;
    }

    if(inOrderStart > inOrderEnd) {                        // inorder me startindex and ending index agr cross kr jaye jo ki invalid condition hai
        return NULL;
    }

    int element = postOrder[postOrderIndex];                //  LRN : so last element ko pick kro kyuki whi root node hai
    postOrderIndex--;

    Node* root = new Node(element);                         // make node
    int ElementIndex = get_index(inorder,element);         // find its index in inorder

    root->right = buildTree(inorder,postOrder,postOrderIndex,ElementIndex+1,inOrderEnd);     //  inorder me element ke right wale sab right subtree me honge
    root->left = buildTree(inorder,postOrder,postOrderIndex,inOrderStart,ElementIndex-1);    // aur left side -> sare left sub tree me honge
   
    return root;

}

Node* buildTree(vector<int>inorder,vector<int>postOrder) {

    int postOrderIndex = postOrder.size() - 1;
    int inOrderStart = 0;
    int inOrderEnd = inorder.size() -1;
    Node* root = buildTree(inorder,postOrder,postOrderIndex,inOrderStart,inOrderEnd);
    return root;

}


int main () {

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postOrder = {9,15,7,20,3};

    Node* root = buildTree(inorder,postOrder); 

    levelOrderTraversal(root);

    return 0;

}