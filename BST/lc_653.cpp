/* return boolean value wether two node exist in BST or not for sum equal to integer k */

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

Node* builBST(Node* root,int data) {

    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(root->data > data) {
        root->left = builBST(root->left,data);
    }
    else{
        root->right = builBST(root->right,data);
    }
}

void takeInput(Node* &root) {

    int val;
    cin>>val;

    while(val != -1) {
        root = builBST(root,val);
        cin>>val;
    }
}

void inorder(Node* root,vector<int>&arr) {

    if(root == NULL) return;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}

bool checkSum(Node* root,int k) {

    if(root == NULL) return false;

    vector<int>arr;
    inorder(root,arr);

    int i = 0;
    int j = arr.size() - 1;
    while(i < j) {
        if(arr[i] + arr[j] == k) return true;
        else if(arr[i] + arr[j] < k) i++;
        else j--;
    }
    return false;
}

int main () {

    Node* root = NULL;
    cout<<"Enter Value : ";
    takeInput(root);

    int k;
    cout<<"Enter Sum : ";
    cin>>k;

    cout<<"Does Exist ? "<<checkSum(root,k)<<endl;

    return 0;

}