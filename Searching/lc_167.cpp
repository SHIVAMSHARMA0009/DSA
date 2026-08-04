// given an sorted array (1-indexed) and target //
// return the index of two number which makes upto  the target //


#include<bits/stdc++.h>
using namespace std;

// Binary search Approach // 
/* T.C -> O(nlog(n))   || S.C -> O(1) */

vector<int> find_indices(vector<int>&nums,int target){

    for(int i=0;i<nums.size();i++){

        int start = i+1;                         // left pointer
        int end = nums.size()-1;                 // right pointer
        int needed = target - nums[i];           // number needed for the current number to make upto the target

        while(start <= end){                      //  search the needed by using binary seacrh
            int mid = start + (end-start)/2;
            if(nums[mid] == needed){
                return {i+1,mid+1};
            }
            else if(nums[mid] > needed){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

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