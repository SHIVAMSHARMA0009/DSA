/* we are given an array and integer k , we have to left rotate an array about k */

#include<bits/stdc++.h>
using namespace std;

class  Solution {
    public:

    // T.C : O(n*k)  S.C : O(1)
    void bruteForce(vector<int>&nums, int k) {

        int n = nums.size();
        if(nums.size() == 0 || nums.size() == 1) return;   // agr array ka size 0 ya 1 hai toh rotation is not possible

        k = k % n;
        if(k == 0) return;    // agr k ki value zero means k has value n & after n rotations , same array will be recovered

        for(int i=0; i<k; i++) {

            int curr = nums[0];       // pehle value ko pakdo aur store kro
            for(int j=1; j<n; j++) {  // phir aage ki sari value ko left me ik ik index shift kro
                nums[j-1] = nums[j];
            }

            nums[n-1] = curr;   // phir jo store kiya tha usko  aakhiri me daalo aur yhi chij K times karo

        }
    }

    // T.C : O(n)  S.C : O(k)
    void better(vector<int>&nums, int k) {
        int n = nums.size();
        if(n <= 1) return;

        k = k % n;
        if(k == 0) return;

        vector<int>temp(k);

        // step 1 : store the k value first
        for(int i=0; i<k; i++) {
            temp[i] = nums[i];
        }

        // step 2 : ab nums ki value ko shift karo  => if k = 2 then to shift kth index value to 0 -> 2 - 2 => i-k
        for(int i=k; i<n; i++) {
            nums[i-k] = nums[i];
        }

        //step 3 : now overwrite the value in original array
        for(int i=0; i<k; i++) {
            nums[n-k+i] = temp[i];
        }
    }


    // T.C : O(n)  || S.C : O(1)
    void reversePart(vector<int>&nums,int i,int j) {
        while(i < j) {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void optimal(vector<int>&nums, int k) {
        int n = nums.size();
        if(n <= 1 ) return;

        k = k%n;
        if(k == 0) return;

        reversePart(nums,0,k-1);
        reversePart(nums,k,n-1);

        reversePart(nums,0,n-1);
    }

};

int main() {
    int n;
    cout<<"Enter The Array Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    int k;
    cout<<"Enter The Value of K : ";
    cin>>k;

    Solution solu;

    // solu.bruteForce(nums, k);
    // cout<<"The Array After K rotation (Brute Force) : ";
    // for(int i=0; i<n; i++) {
    //     cout<<nums[i]<<" ";
    // }

    // solu.better(nums, k);
    // cout<<"The Array After K rotation (Better) : ";
    // for(int i=0; i<n; i++) {
    //     cout<<nums[i]<<" ";
    // }

    solu.optimal(nums, k);
    cout<<"The Array After K rotation (Optimal) : ";
    for(int i=0; i<n; i++) {
        cout<<nums[i]<<" ";
    }

    return 0;

}