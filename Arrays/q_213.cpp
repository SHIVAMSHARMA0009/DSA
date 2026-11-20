// MAXIMUM CONSECUTIVE ONES //

/* we are given binary array -> return the consecutive ones */

#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:

    // Brute force : T.C : O(n^3)  S.C : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int maxcount = 0;

        for(int start=0; start<n; start++) {
            for(int end = start; end<n; end++) {

                bool valid = true;   // flag to check whether subarray satisfies condtion or not

                for(int i=start; i<=end; i++) {
                    if(nums[i] == 0) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    maxcount = max(maxcount,end-start+1);
                }
            }
        }
        return maxcount;
    }

    // Better Approach : T.C : O(n^2)  S.C : O(1)
    int better(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int maxCount = 0;

        for(int start=0; start<n; start++) {
            if(nums[start] == 0) continue;

            int currCount = 0;
            for(int end=start; end<n; end++) {
                if(nums[end] == 0) break;
                currCount++;
                maxCount = max(maxCount, currCount);
            }
        }
        return maxCount;

    }

    // Optimal Approach : T.C : O(n)   S.C : O(1)
    int optimal(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int count = 0;
        int max_count = 0;

        for(auto val : nums) {
            if(val == 1) {
                count++;
            }
            else{
                max_count = max(max_count,count);
                count = 0;
            }
        }

        return max(max_count,count);
    }

};

int main() {

    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Array Data : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution maxOnes;
    cout<<"The Max Consecutive Ones (Brute) : "<<maxOnes.brute(nums)<<endl;
    cout<<"The Max Consecutive Ones (Better) : "<<maxOnes.better(nums)<<endl;
    cout<<"The Max Consecutive Ones (Optimal) : "<<maxOnes.optimal(nums)<<endl;

    return 0;

}