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

    return max(leftsum,rightsum) + root->data;
}

int max_sum(Node* root) {

    if(root == NULL) return 0;

    int sum1 = find_maxi(root->left) + find_maxi(root->right) + root->data;

    int leftsum = max_sum(root->left);
    int rightsum = max_sum(root->right);

    return max({sum1,leftsum,rightsum});

}

// approach 2 : T.C : O(n)
int optimized(Node* root,int &sum) {
    if(root == NULL) return 0;

    int leftsum = optimized(root->left,sum);
    int rightsum = optimized(root->right,sum);

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