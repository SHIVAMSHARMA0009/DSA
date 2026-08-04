/* Given An Array of n-length which consist of integer 1 to n we have to count the number of permutations of this array
  such that arr[i] % i == 0 || i % arr[i] == 0 */

#include<bits/stdc++.h>
using namespace std;

void beautiful_Arrangement(vector<int> &nums,int n,int &count,int currNum){

    if(currNum == n + 1){                // agr curr_number given number exceed kr jaye toh count ko  update kro --> then return
        count++;
        return;
    }

    for(int i=1;i<=n;i++){
        if(nums[i] == 0 && (nums[i] % i == 0 || i % nums[i] == 0)){           // agr condition apply hoti  hai toh
            nums[i] = currNum;                                                // current number of i th index pr rakh do
            beautiful_Arrangement(nums,n,count,currNum+1);                    // aur ussi index pr agle number rakh kr dekho
            nums[i] = 0;                                                      // phir backtrack kro -> taki ussi index pr dusra number rakh kr dekhe 
        }
    }
}

int main(){
    int n;
    cout<<"Enter The Number : ";
    cin>>n;
    vector<int>nums;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
    }

    int count = 0;
    beautiful_Arrangement(nums,n,count,1);

    cout<<"The Number Of Beautiful Arrangement : "<<count;

    return 0;
}