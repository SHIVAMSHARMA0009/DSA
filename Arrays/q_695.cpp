// we are given the array , we have to find the 2nd maximum element from the array

#include<bits/stdc++.h>
using namespace std;


// T.C : O(nlogn)   ||  S.C : O(n)
int bruteMax(vector<int>&nums) {

    int n = nums.size();
    if(n <  2) return -1;

    vector<int>sortedNums = nums;
    sort(sortedNums.begin(),sortedNums.end());

    int largest = sortedNums[n-1];

    for(int i=n-2; i>=0; i--) {
        if(sortedNums[i] < largest) return sortedNums[i];
    }

    return -1;
    
}

// T.C : O(n)   || S.C : O(1)
int betterMax(vector<int>&nums) {

    int n = nums.size();
    if(n < 2) return -1;

    int largest = nums[0];
    for(int i=1; i<n; i++) {
        largest = max(largest,nums[i]);
    }

    int secondLargest = 0;
    bool hasSecond = false;

    for(int i=0; i<n; i++) {
        if(nums[i] < largest) {
            if(!hasSecond || nums[i] > secondLargest) {
                secondLargest = nums[i];
                hasSecond = true;
            }
        }
    }

    if(!hasSecond) return -1;

    return secondLargest;

}

// T.C : O(n)  ||  S.C : O(1)
int optimalMax(vector<int>&nums) {
    int n = nums.size();
    if(n < 2) return -1;

    int largest = nums[0];
    int secondLargest = 0;
    bool hasSecondLargest = false;

    for(int i=1; i<n; i++) {
        if(nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
            hasSecondLargest = true;
        }
        else if(nums[i] < largest) {
            if(!hasSecondLargest || nums[i] > secondLargest) {
                secondLargest = nums[i];
                hasSecondLargest = true;
            }
        }
    }

    if(!hasSecondLargest) return -1;

    return secondLargest;

}



int main() {

    int n;
    cout<<"Enter The Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cout<<"The 2nd Max : "<<bruteMax(nums)<<endl;
    cout<<"The 2nd Max (Better) : "<<betterMax(nums)<<endl;
    cout<<"The 2nd Max (optimal) : "<<optimalMax(nums);

    return 0;

}