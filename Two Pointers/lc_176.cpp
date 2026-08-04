// given an sorted array (1-indexed) and target //
// return the index of two number which makes upto  the target //

#include<bits/stdc++.h>
using namespace std;

/* 2-pointer approach */
/* T.C -> O(n)   || S.C -> O(1) */

vector<int> find_indices(vector<int>&nums,int target){

    int i = 0;                          // left index
    int j = nums.size() - 1;            // right index
 
    while(i<j){
        int sum = nums[i] + nums[j];    // take the sum of both pointer,s element

        if(sum == target){              // if found element equal to target -> then return the indexes immediately
            return {i+1,j+1};
        }
        else if(sum > target){          // if sum is greater , then shift right index towards left
            j--;
        }
        else{                           // else shift left index to  right
            i++;
        }
    }

    return {};                         // if not found any element -> return empty vector

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