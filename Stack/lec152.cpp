/* we are given an array we have to find the next smaller and previous smaller element */

#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>nums) {

    vector<int> ans(nums.size());

    if(nums.size() == 0 ) return {};

    if(nums.size() == 1) return {-1};

    stack<int> st;                        
    st.push(-1);                              // push -1 in stack initially

    for(int i=nums.size()-1;i>=0;i--) {

        int curr = nums[i]; 

        while(st.top() >= curr) {               // pop stack till smaller element is not found
            st.pop();
        }

        ans[i] = st.top();                    // push the smaller element into vector which will be at top of stack after popping

        st.push(nums[i]);                    // then push the current element in the stack as this element can be smaller

    }

    return ans;

}

vector<int> prevSmaller(vector<int> nums) {

    vector<int> ans(nums.size());                             // same approach as above

    if(nums.size() == 0 ) return {};

    if(nums.size() == 1) return {-1};

    stack<int> st;
    st.push(-1);

    for(int i=0;i<nums.size();i++) {

        int curr = nums[i];

        while(st.top() >= curr) { 
            st.pop();
        }

        ans[i] = st.top();

        st.push(nums[i]);

    }

    return ans;

}

int main() {

    int n;
    cout<<"Enter size : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter vector Elements : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> ans1 = nextSmaller(nums);
    cout<<"Next Smaller : ";
    for(auto val : ans1) {
        cout<<val<<" ";
    }
    cout<<endl;

    vector<int> ans2 = prevSmaller(nums);
    cout<<"Previous Smaller : ";
    for(auto val : ans2) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;

}