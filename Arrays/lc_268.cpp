/// MISSING NUMBER ///

/* We are given array of length n , this array contain element in range [0,n] => we have to return the number that is missing from  array in that range */ 


#include<bits/stdc++.h>
using namespace std;

class solution {
    public:

    // T.C : O(n^2)  ||  S.C : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<=n; i++) {     // as range is [0,n] , so search for every element in the array

            bool found = false;       // flag if currrent Number is present or not
            for(auto val : nums) {
                if(val == i) {        
                    found = true;
                    break;
                }
            }
            if(!found) return i;     // if this number is not foudn then return it
        }
        return -1;
    }

    // T.C : O(nlogn)  || S.C : (1)
    int better(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());    // sort the array which means every element is present at same index

        for(int i=0; i<n; i++) {             
            if(i != nums[i]) return i;  // if index value don't matched the array value -> this is missing number
        }

        return n;    // otherwise last range's value is missing
    }

    //  T.C : O(n)  ||  S.C : O(n)
    int opt1(vector<int>& nums) {
        int n = nums.size();

        vector<int> seen(n+1, false);    // array to mark the value present in array
        for(int i=0; i<n; i++) {
            seen[nums[i]] = true;   // mark as true for array value
        }

        for(int i=0; i<seen.size(); i++) {
            if(!seen[i]) return i;          // traverse over the range if any value is not marked that means that is the missing value
        }

        return -1;
    }

    // T.C : O(n)  || S.C : O(1)
    int opt2(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n*(n+1)/2;   // as we have range [0,n] that means sum will be equal to sum of first n natural numbers
        int currSum = accumulate(nums.begin(), nums.end(), 0);   // the current sum of array

        return expectedSum - currSum;   // diffence will be missing value
    }

    // T.C : O(n)  || S.C : O(1) 
    int opt3(vector<int>& nums) {
        int n = nums.size();
        int xorResult = n;          // ? as we have array indices from 0 -> n-1 so to make pair last value of range so we will take size of array
        for(int i=0; i<n; i++) {
            xorResult = xorResult^i;       // as xor cancel out the same number as take xor of index as well as array value
            xorResult = xorResult^nums[i];
        }

        return xorResult;          // xor result will be missing value
    }

};

int main() {
    int n;
    cout<<"Enter the Size of Array : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter The Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    solution missing;
    cout<<"The Missing (Brute) : "<<missing.brute(nums)<<endl;
    cout<<"The Missing (Better) : "<<missing.better(nums)<<endl;
    cout<<"The Missing (Optimal 1) : "<<missing.opt1(nums)<<endl;
    cout<<"The Missing (Optimal 2) : "<<missing.opt2(nums)<<endl;
    cout<<"The Missing (Optimal 3) : "<<missing.opt3(nums)<<endl;

    return 0;
    
}