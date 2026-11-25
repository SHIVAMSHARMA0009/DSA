// MAJORITY ELEMENT //

#include<bits/stdc++.h>
using namespace std;

class solution {
    public:

    //  T.C : O(n^2)   ||    S.C : O(1)
    int brute(vector<int>& nums) {
        int n = nums.size();
        int frequency = n / 2;

        for (int currVal : nums) {      // check every element can be majority element
            int currCount = 0;
 
            for (int value : nums) {
                if (value == currVal) {   // equal value contribute to count of currentVal in the array
                    currCount++;
                }
            }

            if (currCount > frequency) { // if after traversing whole  -> currCount is greater than frequency -> then return currentVal
                return currVal;
            }
        }
 
        return -1;
    }

    // T.C : O(n)     ||   S.C : O(d)    d -> distinct element in the array 
    int better(vector<int>& nums) {
        int frequency = nums.size() / 2;
        unordered_map<int, int> frequencies;
 
        for (int value : nums) {
            frequencies[value]++;     // calculate the frequency of each value

            if (frequencies[value] > frequency) {   // while calculating frequency , any value satisfy condition -> then return it immediately
                return value;
            }
        }
 
        return -1;
    }


    // T.C : O(n)   || S.C : O(1)
    int optimal(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        /* Approach simple hai agr koi array agr N size ka hai aur koi ik element N/2 times se jayda aa rha hai matlab baki elements 
           N/2 se kam aa rhe honge toh ye wale element majority element ko pair-wise cancel out kr sakte hai aur aakri me hamre pass 
           majority element honga
        */

        for (int value : nums) {
            if (count == 0) {                   // agr balance zero hai toh candidate ko store kro 
                candidate = value;              // abhi tak barabar no. of elements mile hai toh pair-wise sabne ik dusre ko cancel out kr diya
            }
 
            if (value == candidate) {    // agr aage wale element match hue toh candidate count ko increase kro
                count++;
            } else {                     // nhi toh candidate count ko decrease kro kyuki N/2times se kam wala element encounter hua hai 
                count--;
            }
        }
 
        return candidate;
    }
    
}; 

int main() {
    int n;
    cout<<"Enter Size of Array : ";
    cin>>n;

    vector<int>nums(n);
    
    cout<<"Enter Array Value : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    solution majority;

    cout<<"The Major Element (Brute) : "<<majority.brute(nums)<<endl;
    cout<<"The Major Element (Better) : "<<majority.better(nums)<<endl;
    cout<<"The Major Element (Optimal) : "<<majority.optimal(nums)<<endl;

    return 0;
}