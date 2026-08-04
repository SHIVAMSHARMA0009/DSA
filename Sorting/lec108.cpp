// MEGRE SORT //

/* It's a Divide & Conquer Technoque where we will keep dividing the array into two halves and start merging that into sorted one to achieve 
   array of original length */

// T.C - > O(nlogn)


#include<bits/stdc++.h>
using namespace std;

void MergeInPlace(vector<int>&nums,int start,int end){

    int total_length = end - start + 1;
    int gap = (total_length) / 2 + (total_length % 2);         // we will use GAP_METHOD to do In_Place Merge Sort

    while(gap > 0){

        int i = start;                                       // As both side arrays were sorted --> do comapare every element to 
        int j = start + gap;                                 // make whole array sorted

        while(j <= end){
            if(nums[i] > nums[j]){                          //if any of element in left found greater then swap it
                swap(nums[i],nums[j]);
            }
            i++,j++;                                       // if not  --> then just increment the indiced
        }
        gap = gap <= 1 ? 0 : (gap/2) + (gap%2);           // then update the GAP_VALUE;
    }
}


void merge(vector<int>&nums,int start,int end){

    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;            // length of left array
    int len2 = end - mid;                  // length of right array

    vector<int>left(len1);                 // created copy to copy vector so that we can merge these two into sorted format
    vector<int>right(len2);

    int k = start;                       // copying the value into arrays
    for(int i=0;i<len1;i++){
        left[i] = nums[k];
        k++;
    }

    k = mid + 1;
    for(int i=0;i<len2;i++){
        right[i] = nums[k++];
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainindex = start;

    while(leftindex < len1 && rightindex < len2){                // pushing element into main array (nums) in sorted format

        if(left[leftindex] < right[rightindex]){
            nums[mainindex++] = left[leftindex++];
        }
        else{
            nums[mainindex++] = right[rightindex++];
        }
    }

    while(leftindex < len1){                                // if any array is longer in left and left with the element -> then push rest of elements
        nums[mainindex++] = left[leftindex++];
    }

    while(rightindex < len2){
        nums[mainindex++] = right[rightindex++];
    }

}

void mergesort(vector<int>&nums,int start,int end){
    
    // Base Case  ->  if pointers are at same index that means we are left with one element which is already sorted
    if(start>=end){
        return;
    }


    int mid = start + (end-start)/2;    // findind index of middle element

    // Left part of array
    mergesort(nums,start,mid);

    // Right part of array
    mergesort(nums,mid+1,end);

    // Merge the two sorted array into one single sorted array

    merge(nums,start,end);   // Takes Space --> O(n)

    MergeInPlace(nums,start,end);   // Take Space --> O(1)

}

int main(){
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter The Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    mergesort(nums,0,n-1);

    cout<<"The Array After Merge Sort : ";
    for(auto val : nums){
        cout<<val<<" ";
    }
    return 0;
}
