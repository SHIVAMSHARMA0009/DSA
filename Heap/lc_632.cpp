/* we are given a 2D array list -> we have to give the range where atleast one element from each list should fall in that range
  if there exist two range given the smallest difference one 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>>&nums) {

  vector<int>ans;

  // tuple : {val,row,col}
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

  int mini = INT_MAX;
  int maxi = INT_MIN;

  for(int row=0;row<nums.size();row++) {

    if(!nums[row].empty()) {
      int val = nums[row][0];                // initialize the min_heap of k size
      pq.push({val,row,0});
      mini = min(mini,val);
      maxi = max(maxi,val);
    }

  }

  int ans_mini = mini;
  int ans_maxi = maxi;

  while(!pq.empty()) {

    auto t = pq.top();             // get details of element at top of min_heap
    int val = get<0>(t);
    int row = get<1>(t);
    int col = get<2>(t);
    pq.pop();

    mini = val;                                 // as we have min_heap => mean every time minimum value will be at top

    if(maxi - mini < ans_maxi - ans_mini) {      // if curr diff of mini & maxi is smaller than update
      ans_mini = mini;
      ans_maxi = maxi;
    }

    if(col + 1 < nums[row].size()) {
      pq.push({nums[row][col+1],row,col+1});     // push the next small element into the heap
      maxi = max(maxi,nums[row][col+1]);
    }
    else{
      break;       // if all rows combingly have been traversed than break
    }

  }

  ans.push_back(ans_mini);
  ans.push_back(ans_maxi);

  return ans;

}

int main() {

  int n;
  cout<<"Enter No. of Row : ";
  cin>>n;

  vector<vector<int>>nums(n);

  cout<<"Enter Data : "<<endl;

  for(int i=0;i<n;i++){

    int m;
    cout<<"Enter Column Size : ";
    cin>>m;

    nums[i].resize(m);
    for(int col=0;col<m;col++) {
      cin>>nums[i][col];
    }

  }

  vector<int>ans = smallestRange(nums);

  cout<<"The Range : "<<ans[0]<<" "<<ans[1]<<endl;

  return 0;

}