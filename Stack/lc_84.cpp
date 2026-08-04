/* we are given an array which represent the height of histogram and each histogram has width of 1 unit -> find out maximum area here */
#include<bits/stdc++.h>
using namespace std;

/* 1st Brute Force : Bar-fixed   ||  T.C : O(n^2)  ||  S.C : (1) */
int largestRectangleArea(vector<int>&height) {

    int leftSmall;              // index of left smaller
    int rightSmall;             // index of right smaller
    int max_area = 0;           // maximum of area

    int b_index = 0;
    while(b_index < height.size()) {

        leftSmall = -1;
        rightSmall = height.size();
        int it = b_index;

        while(it >= 0) {                               // find the index left smaller element
            if(height[it] < height[b_index]) {
                leftSmall = it;
                break;
            }
            it--;
        }

        it = b_index;
        while(it < height.size()) {                  // index of right smaller element
            if(height[it] < height[b_index]) {
                rightSmall = it;
                break;
            }
            it++;
        }

        int width = rightSmall - leftSmall - 1;              // calculate the width
        max_area = max(max_area,width*height[b_index]);       // maximum area

        b_index++;
    }
    return max_area;
}

// /* 2nd Brute Force : range-fixed   ||  T.C : O(n^2)  ||  S.C : (1) */
// int largestRectangleArea(vector<int>&height) {

//     int max_area = 0;

//     for(int i=0;i<height.size();i++) {

//         int min_height = height[i];
//         for(int j=i;j<height.size();j++) {
//             min_height = min(min_height,height[j]);
//             int width = j-i+1;                               // range : 0-6 -> 1-6 -> 2-6  => find minimum bar in every range 
//             max_area = max(max_area,width*min_height);        // find maximum area out of every range
//         }

//     }

//     return max_area;
// }

/* optimal appraoch : stack to store index of left & right smaller element   ||   T.C : O(n)   ||    S.C : O(n)    || */

vector<int> prevSmaller(vector<int>&height) {                        // find index of previous smaller element

    stack<int>st;
    st.push(-1);

    vector<int> ans(height.size());

    for(int i=0;i<height.size();i++) {

        int curr = height[i];

        while(st.top() != -1 && height[st.top()] >= curr) {
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);

    }
    return ans;

}

vector<int> nextSmaller(vector<int>&height) {                     // index of next smaller element

    stack<int>st;
    st.push(-1);

    vector<int> ans(height.size());

    for(int i = height.size()-1;i>=0;i--) {

        int curr = height[i];

        while(st.top() != -1 && height[st.top()] >= curr) {
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);

    }
    return ans;
}


int largestRectangleArea1(vector<int>&height) {

    vector<int>left = prevSmaller(height);
    vector<int>right = nextSmaller(height);

    int max_area = 0;
    int size = height.size();

    for(int i=0;i<size;i++) {
        
        if(right[i] == -1) {                 // if index is -1 then no next smaller element -> means extend till end -> so take array size
            right[i] = size;
        }

        int width = right[i] - left[i] - 1;               // calculate width
        max_area = max(max_area,height[i]*width);        // find max_area

    }

    return max_area;

}

int main () {

    int n;
    cout<<"Enter no. of histogram Histogram : ";
    cin>>n;

    vector<int> height(n);
    cout<<"Enter Height Of Histogram : ";
    for(int i=0;i<n;i++) {
        cin >> height[i];
    }

    cout<<"The Maximum Area (Brute Force) : "<<largestRectangleArea(height)<<endl;
    cout<<"The Maximum Area (Optimal) : "<<largestRectangleArea1(height)<<endl;

    return 0;
}