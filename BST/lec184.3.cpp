/* Inorder predecessor / Successor of any element  */
/* if we store the inorder traversal of tree , then the number just before (i-1)th will be predecessor & (i+1)th will be successor  */
/* e.g : 2 4 6 7 8 9 10   => for 7 (predecssor : 6 & successor : 8)  but there will be no predecessor for 2 and successor for 10 */



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


/* approach 1 : first we will locate the key in BST  , predecessor will be max element in left subtree of key and successor will be min element in right subtree of key */
/* but it lacks for node which don't have right or left sub tree */

int max_element(Node* root) {

    if(root == NULL) return -1;

    while(root->right) root = root->right;

    return root->data;

}

int min_element(Node* root) {

    if (root == NULL) return -1;

    while(root->left) root = root->left;

    return root->data;
}

int find_pred(Node* root ,int key) {

    if(root == NULL) return -1;

    if(root->data == key) {
        return max_element(root->left);
    }

    if(root->data > key) {
        return find_pred(root->left,key);
    }
    else{
        return find_pred(root->right,key);
    }

}

int find_succ(Node* root,int key) {

    if(root == NULL) return -1;

    if(root->data == key) {
        return min_element(root->right);
    }

    if(root->data > key) {
        return find_succ(root->left,key);
    }
    else{
        return find_succ(root->right,key);
    }
}

/* Optimal approach : store the inorder traversal in vector -> give the predecessor and successor */

void inOrder(Node* root,vector<int>&arr) {     // LNR

    if(!root) return;

    inOrder(root->left,arr);
    arr.push_back(root->data);
    inOrder(root->right,arr);

}

pair<int,int> find_both(Node* root,int key) {

    vector<int>arr;
    inOrder(root,arr);

    for(int i=0;i<arr.size();i++) {

        if(arr[i] == key) {
            int pred = (i > 0) ? arr[i-1] : -1;                          // no predecessor for first element    
            int succ = (i < arr.size() - 1) ? arr[i+1] : -1;             // no successor for  last element
            return {pred,succ};
        }
    }
    return {-1,-1};
}


int main() {

    Node* root = NULL;
    cout<<"Enter The Node Value : ";
    takeInput(root);

    int key;
    cout<<"Enter The Key : ";
    cin>>key;

    cout<<"The Predecessor : "<<find_pred(root,key)<<endl;

    cout<<"The Successor : "<<find_succ(root,key)<<endl;

    pair<int,int>b = find_both(root,key);
    cout<<"The Predecessor & Successor : "<<b.first<<" "<<b.second;

    return 0;

}
