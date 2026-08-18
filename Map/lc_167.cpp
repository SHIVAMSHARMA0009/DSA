// given an sorted array (1-indexed) and target //
// return the index of two number which makes upto  the target //


#include<bits/stdc++.h>
using namespace std;

// Hash-Map Approach // 
/* T.C -> O(n)   || S.C -> O(n) */

vector<int> find_indices(vector<int>&nums,int target){

    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){       

        int needed = target - nums[i];   // find number needed to make upto the sum for the current number

        if(mp.count(needed)){              // if we have mapped the needed element earlier in the hash_map
            return {mp[needed]+1,i+1};     // then return the index of needed  element then the index of current element
        }
        mp[nums[i]] = i;                   // otherwise map the current element with its index value
    }

    return {};

}

int main(){
    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Number of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int target;
    cout<<"Enter The Target : ";
    cin>>target;

    vector<int>index = find_indices(nums,target);

    cout<<"The Indexes : ";
    for(auto val : index){
        cout<<val<<" ";
    }

    return 0;

}