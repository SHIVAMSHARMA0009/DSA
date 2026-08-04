/* SLIDING WINDOW MAXIMUM */

#include<bits/stdc++.h>
using namespace std;

// T.C : O(n+k) ~ O(n)     ||     S.C : O(n-k+1) ~ O(n)     ||
vector<int> maxWindowEle(vector<int>&nums,int k) {

    deque<int>dq;
    vector<int>ans;

    // push index of element in queue for first window of k size
    for(int i=0;i<k;i++) {

        // if current element is greater than the element with index stored at back of queue => then remove them
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);     // then push the index of current element so that we can compare in future
    }

    ans.push_back(nums[dq.front()]);    // index of maximum element will be at front => push it to ans vector
    
    // traverse remaining window
    for(int i=k;i<nums.size();i++) {

        // out of window ke index ko remove kro
        if(i - dq.front() >= k && !dq.empty()) {
            dq.pop_front();
        }

        // if current element is greater than the element with index stored at back of queue => then remove them
        while(!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);  // then push the index of current element so that we can compare in future

        ans.push_back(nums[dq.front()]);  // index of maximum element for current window will be at front => push it to ans vector

    }

    return ans;
}

int main() {

    int n;
    cout<<"Enter The Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Value : ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    int k;
    cout<<"Enter Window Size : ";
    cin>>k;
    
    vector<int>maxi = maxWindowEle(nums,k);

    cout<<"The Maxium For Every Window : ";
    for(auto val : maxi) {
        cout<<val<<" ";
    }

    return 0;

}