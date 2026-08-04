/* Given An Array We Have To Reverse It */

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&nums){
    
    int i = 0;
    int j = nums.size() - 1;
    while(i <= j){
        swap(nums[i++],nums[j--]);
    }

}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array Elements : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    reverse(nums);

    cout<<"The Array After Reversing : ";
    for(auto val : nums){
        cout<<val<<" ";
    }

    return 0;
}