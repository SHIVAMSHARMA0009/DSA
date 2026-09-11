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

Node* buildTree() {

    int rootData;
    cin>>rootData;

    if(rootData == -1) {
        return NULL;
    }

    Node* root = new Node(rootData);

    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftData;
        cin>>leftData;
        if(leftData != -1){
            curr->left = new Node(leftData);
            q.push(curr->left);
        }
        

        int rightData;
        cin>>rightData;
        if(rightData != -1){
            curr->right = new Node(rightData);
            q.push(curr->right);
        }
    }
    return root;
}

void left_view(Node* root) {
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        for(int i=0;i<n;i++) {
            Node* curr = q.front();
            q.pop();
            if(i == 0) cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

int main() {

    cout<<"Enter Tree Value : ";
    Node* root = buildTree();

    cout<<"The left View : ";
    left_view(root);

    return 0;
}