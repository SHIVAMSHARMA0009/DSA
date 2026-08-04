/* find first -ve number in window of size k of vector */

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>nums,int k) {

    deque<int>q;


    // process first window
    for(int i=0;i<k;i++) {
        if(nums[i] < 0){
            q.push_back(i);
        }
    }

    // remaining process
    for(int i=k;i<nums.size();i++) {

        //find ans for old window
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<nums[q.front()]<<" ";
        }

        // out of window element ke index ko remove kro queue se
        while(!q.empty() && i - q.front() + 1 >= k) {
            q.pop_front();
        }

        // check current element for insertion
        if(nums[i] < 0) {
            q.push_back(i);
        }
    }

    // answer for last window
    if(q.empty()){
        cout<<0<<" ";
    }
    else{
        cout<<nums[q.front()]<<" ";
    }

}

int main () {

    int n;
    cout<<"Enter Vector Size : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Vector Values : ";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    int k;
    cout<<"Enter The Window Size : ";
    cin>>k;

    solve(nums,k);

    return 0;

}