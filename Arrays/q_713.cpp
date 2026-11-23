/// UNION OF 2 VECTORS ///

#include<bits/stdc++.h>
using namespace std;

class solution {

    public:

    // T.C : O((m+n)^2)  ||  S.C : O(1)
    vector<int> brute(vector<int> nums1, vector<int> nums2) {

        vector<int>unionResult;

        auto addUnique = [&](int val) {
            for(int num : unionResult) {           // if element is already present in result vector -> then don't  insert its
                if(num == val) return;                   
            }
            unionResult.push_back(val);              // otherwise insert it into final  ans array
        };

        for(auto val : nums1) {
            addUnique(val);
        }

        for(auto val : nums2) {
            addUnique(val);
        }

        sort(unionResult.begin(), unionResult.end());            // sort the array in  ascending order

        return unionResult;
    }


    // T.C : O((m+n)log(m+n))  ||  S.C : O(m+n)
    vector<int> better(vector<int>nums1, vector<int>nums2) {
        
        set<int>st;
        for(auto val : nums1) {           // insert into set as set stores  unique value in sorted order
            st.insert(val);
        }

        for(auto val : nums2) {
            st.insert(val);
        }

        vector<int> unionResult(st.begin(), st.end());

        return unionResult;

    }


    // T.C : O(m+n)  || S.C : (1)
    vector<int> optimal(vector<int>nums1, vector<int>nums2) {

        vector<int>unionResult;
        int n = nums1.size();
        int m = nums2.size();

        int i=0;
        int j=0;
        while(i<n && j<m) {                          // as both the arrays are sorted
            int currVal;
            if(nums1[i] < nums2[j]) {               // compare element of both the arrays from left side
                currVal = nums1[i];                 // whose value is smaller store it and increment its pointer
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                currVal = nums2[j];
                j++;
            }
            else{
                currVal = nums1[i];
                i++;
                j++;
            }

            if(unionResult.empty() || unionResult.back() != currVal) {   // if result is empty or last element of resultant array is not equal currValue then store it in result  
                unionResult.push_back(currVal);                          // as we are storing element in sorted that means last element will be always bigger 
            }
        }

        while(i < n) {                                                          // after this all smaller value from both array willbe stored completely
            if(unionResult.empty() || unionResult.back() != nums1[i]) {         // then store the rest value 
                unionResult.push_back(nums1[i]);
            }
            i++;
        }

        while(j < m) {
            if(unionResult.empty() || unionResult.back() != nums2[j]) {
                unionResult.push_back(nums2[j]);
            }
            j++;
        }

        return unionResult;
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

    solution uni;

    vector<int> result1 = uni.brute(nums1, nums2);
    cout<<"The Array (Brtue) : ";
    for(auto val : result1) {
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> result2 = uni.better(nums1, nums2);
    cout<<"The Array (Better) : ";
    for(auto val : result2) {
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> result3 = uni.optimal(nums1, nums2);
    cout<<"The Array (Optimal) : ";
    for(auto val : result3) {
        cout<<val<<" ";
    }

    return 0;
}