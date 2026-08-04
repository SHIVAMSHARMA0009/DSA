/* we are given an array we have print extreme ends of the array */

#include<bits/stdc++.h>
using namespace std;

void print_ends(vector<int>&nums){

    int left = 0;
    int right = nums.size() -1 ;

    while(true){

        if(left > right){
            break;
        }

        if(left == right){
            cout<<nums[left];
        }
        else{
            cout<<nums[left]<<" "<<nums[right]<<" ";
        }

        left++;
        right--;

    }

}

int main(){

    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Values Of Array : ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    print_ends(nums);

    return 0;
}
