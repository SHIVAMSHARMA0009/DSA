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

Node* buildtree() {

    int val;
    cin >> val;

    if(val == -1) {
        return NULL;
    }

    Node* root = new Node(val);

    root->left = buildtree();
    root->right = buildtree();

    return root;
}

// approach 1 : T.C : O(n^2)
int find_maxi(Node* root) {
    if(root == NULL)  return 0;

    int leftsum = find_maxi(root->left);
    int rightsum = find_maxi(root->right);

    return max({0,leftsum,rightsum}) + root->data;    // ignore -ve sum from left ans right tree
}

int max_sum(Node* root) {

    if(root == NULL) return INT_MIN;

    int sum1 = max(0,find_maxi(root->left)) + max(0,find_maxi(root->right)) + root->data;    //ignore -ve sum from left ans right tree

    int leftsum = max_sum(root->left);
    int rightsum = max_sum(root->right);

    return max({sum1,leftsum,rightsum});

}

// approach 2 : T.C : O(n)
int optimized(Node* root,int &sum) {
    if(root == NULL) return 0;

    int leftsum = max(optimized(root->left,sum),0);       // ignore negative number
    int rightsum = max(optimized(root->right,sum),0);

    int curr_sum = leftsum + rightsum + root->data;

    sum = max(sum,curr_sum);

    return max(leftsum,rightsum) + root->data;

}

int main() {

    cout<<"Enter Data : ";
    Node* root = buildtree();

    int sum = INT_MIN;
    optimized(root,sum);
    cout<<"The Sum : "<<sum<<endl;
    return 0;

}