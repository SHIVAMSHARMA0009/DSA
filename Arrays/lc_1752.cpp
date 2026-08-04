/* We are given an array --> check Is it Sorted and Rotated Once if --> Yes return true , otherwise return false */

#include<bits/stdc++.h>
using namespace std;

bool check_condition(vector<int>&nums){

    int n = nums.size() - 1;
    bool pivot = false;

    for(int i=0;i<n-1;i++){                    /* we will traverse array if we found current element greater than next , we will mark pivot true*/
        if(nums[i] > nums[i+1]){               /* so ahead if we found any element greater than next one --> immediately return false */
            if(pivot){
                return false;
            }
            pivot = true;
        }
    }

    if(pivot && (nums[0] <  nums[n-1])) return false;   /* IF CONDITION MEETS AND THEIR IS PIVOT ELEMENT 
                                                           THEN FIRST ELEMENT SHOULD BE GREATER THAN LAST ELEMENT */

    return true;                             /* At the end if condition meets -> return true */

}

int main(){
    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;

    cout<<"Enter The Array : ";
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    bool is_sorted = check_condition(nums);

    if(is_sorted){
        cout<<"The Given Array is Rotated And Sorted !!";
    }
    else{
        cout<<"The Array is Not Sorted And Rotated";
    }

    return 0;
}