/* we are given an sorted array , we have to remove the duplicates from the array and array the no. of unique elements and unique must be starting of 
   original array */

#include<bits/stdc++.h>
using namespace std;

class RemoveDuplicates {

    public:

    // T.C : O(n^2)    S.C : (n)
    int bruteForce(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int>temp;     // stores the unique

        for(auto num : nums) {                          // we will take each element of the original
            bool hasDuplicates = false;    

            for(auto val : temp) {
                if(val == num) {                         // if the same element is found in the temp array means its duplicate -> don't count it
                    hasDuplicates = true;
                    break;
                }
            }

            if(!hasDuplicates) temp.push_back(num);
        }

        for(int i=0; i<temp.size(); i++) {  // now copy into original so that first k show unique elements
            nums[i] = temp[i];
        }

        return temp.size();
    }

    int better(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        vector<int>temp;
        temp.push_back(nums[0]);                  // store first element into temp array as it will store unique

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[i-1]) {            // as array is sorted , breaking point will be element not equal to previous element
                temp.push_back(nums[i]);          // means push the element
            }
        }

        for(int i=0; i<temp.size(); i++) {    // now copy all the k element to original nums
            nums[i] = temp[i];
        }

        return temp.size();
    }

    int optimal(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int initialPosition = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                nums[initialPosition] = nums[i];
                initialPosition++;
            }
        }

        return initialPosition;

    }

};

int main() {

    int n;
    cout<<"Enter Size Of Array : ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Value Of Array : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    RemoveDuplicates sol;
    cout<<"The Unique Value : "<<sol.bruteForce(nums)<<endl;
 //   cout<<"The Unique Value : "<<sol.better(nums)<<endl;
 //   cout<<"The Unique Value : "<<sol.optimal(nums)<<endl;

    return 0;

}