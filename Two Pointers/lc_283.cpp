/* We are given with array where we have to move zero to end while maintaining order of non-zero numbers */

#include<bits/stdc++.h>
using namespace std;

/* Slow - Fast 2 pointer approach where i-th as fast and j-th as slow pointer (if condition meets then move slower index) l*/


// brute force solution : ? S.C == O(n)
void move_zeroes(vector<int>&nums){

    int n = nums.size();       
    vector<int> temp(n,0);              //taking temporary vector so that we can store it  all positive num at starting

    int index = 0;
    for(auto val : nums){
        if(val != 0){
            temp[index++] = val;       // storing values in temp as copy
        }
    }

    for(int i=0;i<n;i++){
        nums[i] = temp[i];           // now over-writing the temp into original vector
    }
}


// optimize solution : S.C = O(1)
void move_zeroes(vector<int>&nums){

    int n = nums.size();

    int j = -1;              // want store first index of zero
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            j = i;
            break;          // if got index then restore & immediately come out of loop
        }
    }

    if(j == -1) return;    // if j remains unchanges that means array doesn't contain any zero then return same array

    for(int i=j+1;i<n;i++){                 // if j has been changes

        if(nums[i]!=0){                    // if value next(i-index) to j is not zero then 
            swap(nums[i],nums[j]);         // swap that that non-zero number with zero(present at j-index)
            j++;                           // then move j to next zero as zero will move to i-index
        }
    }
}

int main(){
    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    move_zeroes(nums);

    cout<<"The Modified Array : ";
    for(auto val : nums){
        cout<<val<<" ";
    }

    return 0;
}