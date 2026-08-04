// we are given with a sorted (1-indexed) array and a target //

/* we have to return index of two numbers which makes upto the target */

#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE SOLUTION //

/* T.C -> O(n^2)   ||   S.C -> O(1) */

vector<int> find_indices(vector<int>&nums,int target){

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] + nums[j] == target){
                return {i+1,j+1};
            }
        }
    }

    return {};
}

int main(){
    int n;
    cout<<"Enter Size of Vector : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Number Of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cout<<"Enter The Target : ";
    cin>>target;

    vector<int>index = find_indices(nums,target);
    
    cout<<"The Indices  : ";
    for(auto val : index){
        cout<<val<<" ";
    }

    return 0;
}

// 2 ->  two pointer solution
// 3 ->  hash map solution
// 4 -> binary search solution