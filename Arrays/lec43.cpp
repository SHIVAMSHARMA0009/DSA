/* Given An Array Reverse The Array */

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&nums){

    int n = nums.size() - 1;
    for(int i=n;i>=0;i--){
        cout<<nums[i]<<" ";
    }

}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Values Of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    reverse(nums);

    return 0;
}