// COUNT INVERSION PROBLEM //

/* Given an unsorted array where we have indices i & j such that     [ i < j and arr[i] > arr[j] --> COUNT INVERSION CONDITIONS ]
   so find minimum no. of swap needed to make array sorted */

#include<bits/stdc++.h>
using namespace std;


// Optimized Solution through Merge Sort  -- >    T.C = O(nlogn) || S.C O(n)

long merge(vector<int>&nums,vector<int>&temp,int start,int end){

    int mid = start + (end - start)/2;

    int i = start , j = mid + 1 , k = start;                // i -> starting indices of left side & j -> starting indices of right side
                                                            // k -> index from which we will add value to temp in sorted form

    long count_inversion = 0;

    while(i <= mid && j <= end){                           // here we copying value to temp so  that  we can update values in main array
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++]; 
        }
        else{                       // this is count_inversion condition 
            temp[k++] = nums[j++];
            count_inversion += mid - i + 1;       /* as we know left side will be sorted one so if we compare the first element of right array
                                                     with very first element of left array if left will be GREATER + (i < j) & next element in left part 
                                                     will also be greater so no. of swap needed will (mid - i + 1)*/
        }
    }

    while(i <= mid){                            // pushing rest elements in temp if any one part is bigger in length
        temp[k++] = nums[i++];
    }

    while(j <= end){
        temp[k++] = nums[j++];
    }

    while(start <= end){                    // pushing temp into original array nums
        nums[start++] = temp[start++];
    }

    return count_inversion;
}

long mergesort(vector<int>&nums,vector<int>&temp,int start,int end){
    if(start >= end) {
        return 0;
    }

    int mid = start + (end - start)/2;

    int count_inversion = 0;

    count_inversion += mergesort(nums,temp,start,mid);           // minimum swap in left side

    count_inversion += mergesort(nums,temp,mid+1,end);           // minimum  swap in right side

    count_inversion += merge(nums,temp,start,end);               // minimum swap  after merging array of both side

    return count_inversion;
}


// Brute Force Solution  -->       T.C = O(n^2) ||  S.C = O(1)

void brute_force(vector<int>&nums){

    long count_inversion = 0;

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            count_inversion = nums[i] > nums[j] ? count_inversion + 1 : count_inversion;
        }
    }

    cout<<"The Number Of Swap Needed  : "<<count_inversion;


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

    brute_force(nums);

    vector<int>temp(nums.size(),0);                                      // passed the array temp to store value in sorted form

    cout<<"The Number Of Swaps Needed : "<<mergesort(nums,temp,0,n-1);
    
    return 0;
}