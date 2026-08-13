/* we have to return the kth smallest from the array */

/* APPROACH : max_heap :
                         first take the max_heap of k size
                         after traversing the whole array , only k small element will be in the heap at the end
                         if top of heap is greater than array element , replace it with array element -> at the end heap top will be kth smallest element
*/

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>&nums,int k) {

    priority_queue<int>pq;                      // max heap
    for(int i=0;i<k;i++) {
        pq.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++) {
        if(pq.top() > nums[i]) {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int kthLargest(vector<int>&nums,int k) {

    priority_queue<int,vector<int>,greater<>>pq;     // min heap
    for(int i=0;i<k;i++) {
        pq.push(nums[i]);
    }

    for(int i=k;i<nums.size();i++) {
        if(pq.top() < nums[i]) {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int main() {

    int n;
    cout<<"Enter Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Array Value : ";
    for(int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int k;
    cout<<"Enter K value : ";
    cin>>k;

    cout<<"The Kth Smallest Element in the Array : "<<kthSmallest(nums,k)<<endl;
    cout<<"The Kth Largest Element in the array : "<<kthLargest(nums,k)<<endl;

    return 0;
    
}
