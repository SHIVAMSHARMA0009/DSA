/* We are given an array we have to find the unique element from it */

#include<bits/stdc++.h>
using namespace std;

vector<int> find_unique(vector<int>&nums){

    vector<int>result;

    unordered_map<int,int>mp;
    for(auto val : nums){
        mp[val]++;
    }

    for(auto itr : mp){
        if(itr.second == 1){
            result.push_back(itr.first);
        }
    }

    return result;

}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Value : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int>unique = find_unique(nums);

    if(unique.empty()){
        cout<<"Unique Don't Exist !!";
    }
    else{
        cout<<"The Element : ";
        for(auto val : unique){
        cout<<val<<" ";
        }
    }

    return 0;

}