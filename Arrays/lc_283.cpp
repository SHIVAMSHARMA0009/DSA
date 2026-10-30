/*we are given an array , we have to move all zeroes to the end */

#include<bits/stdc++.h>
using namespace std;

class MoveZeroes {
    public:

    // T.C : O(n)   S.C : O(n)
    void bruteForce(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;

        vector<int>temp;

        for(int i=0; i<n; i++) {                  // first preserve the non-zero numbers
            if(nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        // after preserving , push the zeroes into temp so that it could become size equal to original array
        while(temp.size() < n) {
            temp.push_back(0);
        }

        // now copy all the element of into original nums
        for(int i=0; i<n; i++) {
            nums[i] = temp[i];
        }
    }


    // T.C: O(n)  S.C : O(1)
    void better(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;

        int initialPosition = 0;   // it will track the position of non-zero and will make sure that all non-zeros are stored in same order
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[initialPosition] = nums[i];
                initialPosition++;
            }
        }

        // after above loop -> the order of all non-zero has begin preserved
        // now push zero till the value of pointer bacomes equal to size of array
        while(initialPosition < n) {
            nums[initialPosition++] = 0;
        }
    }

    // T.C : O(n)   S.C : O(1)
    void optimal(vector<int>& nums) {   // just in one pass
        int n = nums.size();
        if(n <= 1) return;

        int zeroPosition = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                swap(nums[zeroPosition++],nums[i]);
            }
        }
    }
};

int main() {
    
    int n;
    cout<<"Enter Array Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    MoveZeroes sol;

    sol.optimal(nums);
    cout<<"The Array (Brtue Force) : ";
    for(auto val : nums) {
        cout<<val<<" ";
    }

    sol.better(nums);
    cout<<"The Array (Better) : ";
    for(auto val : nums) {
        cout<<val<<" ";
    }

    sol.optimal(nums);
    cout<<"The Array (Optimal) : ";
    for(auto val : nums) {
        cout<<val<<" ";
    }

    return 0;
    
}