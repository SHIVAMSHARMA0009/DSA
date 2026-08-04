// QUICK SORT //

/* Another Divide & Conquer Technique which works on two ways -> partition & recursive logic */

/* Here we will pick one(PIVOT) element , then will find its correct(PIVOT) index and will put this element over there after putting split array into 
   two part such that it should contain smaller element at left and greater element at right at PIVOT elemen t*/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&nums,int start,int end){

    int pivotIndex = start;                         // taking starting element as pivot_element
    int pivot_element = nums[start];

    int count = 0;                                 // counting how many element are lower than the pivotelement so that we can find its correct index
    for(int i=start+1;i<=end;i++){
        if(nums[i] <= pivot_element){
            count++;
        }
    }

    int rightindex = start + count;                // correct index of pivot_element
    swap(nums[pivotIndex],nums[rightindex]);       // placing pivot_element at correct position
    pivotIndex = rightindex;

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex){

        while(nums[i] <= pivot_element) i++;       // if left part is smaller update poointer's index
        while(nums[j] > pivot_element)  j--;       // if right part is smaller update poointer's index

        if(i < pivotIndex && j > pivotIndex){  
            swap(nums[i++],nums[j--]);                 // if not then -> place at correct side of array
        }
    }
    return pivotIndex; 
}

void quicksort(vector<int>&nums,int start,int end){
    
    // Base Case  ->  if pointers are at same index that means we are left with one element which is already sorted
    if(start >= end){
        return;
    }

    // finding index of  pivot element
    int pivot_index = partition(nums,start,end);

    // Sorting left part after putting pivot_element at correct index
    quicksort(nums,start,pivot_index-1);          

    // Sortinf right part after putting pivot_element at correct index
    quicksort(nums,pivot_index+1,end);

}

int main(){
    int n;
    cout<<"Enter The Size of Array : ";
    cin>>n;
    
    vector<int>nums(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    quicksort(nums,0,n-1);

    cout<<"The Array after Quick sort : ";
    for(auto val : nums){
        cout<<val<<" ";
    }

    return 0;
}