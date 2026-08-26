/* We are given an array we have to find the unique element from it */

/* Approach 1 : running XOR operation through whole array [only works if remaining element are in pairs] */

/* val ^ val = 0 */

/* Approach 2 : HASHMAP APPROACH : Array may have many unique elements so to find many unique elements count frequency */

#include<bits/stdc++.h>
using namespace std;

int unique_element(vector<int>&nums){

    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans = ans^nums[i];
    }

    return ans;
}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter Value Of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"The Unique Element Of Array : "<<unique_element(nums);

    return 0;

}