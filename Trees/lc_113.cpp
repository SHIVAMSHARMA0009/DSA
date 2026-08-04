/* given a tree with target -> return the paths which has sum upto target */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {

    int val;
    cin>>val;

    if(val == -1){
        return NULL;
    }
    else{
        Node* root = new Node(val);
        root->left = buildTree();
        root->right = buildTree();
    }
}

void solve (Node* root,int target,int curr_sum,vector<int>temp,vector<vector<int>>&path) {

    if(root == NULL) return;

    // we reached the leaf node
    if(root->left == NULL && root->right == NULL) {
        temp.push_back(root->data);
        curr_sum += root->data;
        if(curr_sum == target) {
            path.push_back(temp);
        }
        return;
    }

    // include the current node and value;
    temp.push_back(root->data);
    curr_sum += root->data;

    solve(root->left,target,curr_sum,temp,path);
    solve(root->right,target,curr_sum,temp,path);


}

vector<vector<int>> find_path(Node* root,int target) {

    vector<vector<int>> path;
    vector<int>temp;
    int curr_sum = 0;
    solve(root,target,curr_sum,temp,path);

    return path;

}

int main() {
     
    Node* root = buildTree();

    int target;
    cout<<"Enter Target : ";
    cin>>target;


    vector<vector<int>>path = find_path(root,target);

    cout<<"The Path : ";
    for(auto v1 : path) {
        for(auto val : v1) {
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;

}