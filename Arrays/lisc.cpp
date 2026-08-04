/* we are given an array we have to search for element linearly */

#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int>&nums,int val){
    for(int i=0;i<nums.size();i++){
        if(nums[i] == val){
            return i;
        }
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Values of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int val;
    cout<<"Enter Element to Search : ";
    cin>>val;

    int index = linearsearch(nums,val);

    if(index >= 0){
        cout<<val<<" Found At Index : "<<index+1;
    }
    else{
        cout<<"OOPs !! , Element Not Found";
    }

    return 0;

}