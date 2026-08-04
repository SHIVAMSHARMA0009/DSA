/* Given an array which contain positive as well as negative numbers --> we have to subarray which return maximum sum */

#include<bits/stdc++.h>
using namespace std;

int Max_SubArray(vector<int>&nums,int start,int end){

    if(start >= end){                                  // we will keep dividing the array like in merge sort --> will return always starting element
        return nums[start];
    }

    int mid = start + (end - start) / 2;

    int Max_LeftBorderSum = INT_MIN, Max_RightBorderSum = INT_MIN;

    int Max_LeftSum = Max_SubArray(nums,start,mid);     // we will find what is maximum Sum to the left of mid (including it)

    int Max_RightSum = Max_SubArray(nums,mid+1,end);    // we will find what is maximum sum to right of mid

    int Left_Sum = 0 , Right_Sum = 0;

    for(int i = mid ; i >= start ; i--){             //
        Left_Sum += nums[i];
        if(Left_Sum > Max_LeftBorderSum){
            Max_LeftBorderSum = Left_Sum;
        }
    }

    for(int i = mid + 1;i <= end; i++){
        Right_Sum += nums[i];
        if(Right_Sum > Max_RightBorderSum){
            Max_RightBorderSum = Right_Sum;
        }
    }

    int Cross_BorderSum = Max_LeftBorderSum + Max_RightBorderSum;    // then may be maximum_sum lie in-between the array -> so find cross border sum

    return max(Cross_BorderSum,max(Max_LeftSum,Max_RightSum));       // now return the maximum of three results
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

    cout<<"The Maximun Sum Of Array : "<<Max_SubArray(nums,0,n-1);

    return 0;
}