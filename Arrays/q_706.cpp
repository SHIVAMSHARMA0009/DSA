// FIND INTERSECTION OF 2 ARRAYS //

#include<bits/stdc++.h>
using namespace std;


class solution {
    public:

    // T.C : O(m x n)  ||  S.C : O(1)
    vector<int> brute(vector<int>& nums1, vector<int>& nums2) {

        vector<int> intersectionResult;
 
        for (int val1 : nums1) {
            bool foundInSecond = false;
 
            // Search for the current value in nums2.
            for (int val2 : nums2) {
                if (val2 == val1) {
                    foundInSecond = true;         // if we found the element of 1st array in 2nd means this is intersection 
                    break;
                }
            }
 
            if (!foundInSecond) {         // if not found means no common values for current interation
                continue;
            }
 
            bool alreadyAdded = false;
 
            for (int storedValue : intersectionResult) {         // Here , we will check is current matching value is present in result or not
                if (storedValue == val1) {
                    alreadyAdded = true;
                    break;
                }
            }
 
            // Add only the first occurrence of a common value.
            if (!alreadyAdded) {
                intersectionResult.push_back(val1);
            }
        }
 
        return intersectionResult;
    }


    // T.C : O(m + n + rlogr) r => distinct element   || S.C : O(n + r)
    vector<int> better(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> firstSet;          // set stores unique value which remove duplicates
        unordered_set<int> intersectionSet;
 
        // Store values from the first array.
        for (int value : nums1) {
            firstSet.insert(value);
        }
 
        for (int value : nums2) {                          
            if (firstSet.find(value) != firstSet.end()) {   // if value of 2nd array doesn't find in intersection set (remove duplicates)
                intersectionSet.insert(value);              // then insert the value into ans_set
            }
        }
 
        vector<int> intersectionResult(
            intersectionSet.begin(),
            intersectionSet.end()
        );
 
        sort(intersectionResult.begin(), intersectionResult.end());   // sort the resultant vector
 
        return intersectionResult;
    }


    // T.C : O(m+n)   ||  S.C : O(1)
    vector<int> optimal(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
 
        int i = 0;
        int j = 0;
 
        vector<int> intersectionResult;
 
        while (i < n && j < m) {          // as both the arrays are sorted use 2-pointer and insert whose value is smaller and increment pointer
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                if (intersectionResult.empty() || intersectionResult.back() != nums1[i]) {    // 1. include current element if ans is empty 
                    intersectionResult.push_back(nums1[i]);                                   // 2. to make sure we don't store duplicate , check back of ans array as both the arrays are in sorted order
                }                                                                             //     ans storing smaller element first
                i++;
                j++;
            }
        }
        return intersectionResult;
    }

};

int main() {
    int n, m;
    cout<<"Enter Size of 1st & 2nd Array : ";
    cin>>n>>m;

    vector<int>nums1(n);
    vector<int>nums2(m);

    cout<<"Enter 1st Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums1[i];
    }

    cout<<"Enter 2nd Array Value : ";
    for(int i=0; i<m; i++) {
        cin>>nums2[i];
    }

    solution intersection;

    vector<int> result1 = intersection.brute(nums1, nums2);
    cout<<"The Intersection (Brtue) : ";
    for(auto val : result1) {
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> result2 = intersection.better(nums1, nums2);
    cout<<"The Intersection (Better) : ";
    for(auto val : result2) {
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> result3 = intersection.optimal(nums1, nums2);
    cout<<"The Intersection (Optimal) : ";
    for(auto val : result3) {
        cout<<val<<" ";
    }

    return 0;
}