/* Minimum cost of rope => if we want to combine two ropes into one signle rope => the cost will be sum of there length 
   Minium the total cost so that , we can combine all the ropes of given length  
*/

/* APPROACH : push the whole array into min_heap => then pop out two element as top 2 elements will smallest one , so their sum will be smallest one
              now take sum and push back to heap and update the total_cost by adding the sum to total cost
*/

#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>&nums) {

   priority_queue<int,vector<int>,greater<int>>pq;

   int total_cost = 0;

   for(int i=0;i<nums.size();i++) {
      pq.push(nums[i]);
   }

   while(pq.size() > 1) {

      int len1 = pq.top();        // top two will be smallest in the queue  ->  therfore cost will remain minium to join two
      pq.pop();
      int len2 = pq.top();
      pq.pop();
      
      int cost = len1 + len2;    
      pq.push(cost);                  //  push the cost of two as single rope in the queue

      total_cost += cost;             // update the total cost

   }

   return total_cost;

}

int main() {

   int n;
   cout<<"Enter No. of Ropes : ";
   cin>>n;

   vector<int>ropes(n);
   cout<<"Enter Rope Length : ";
   for(int i=0;i<n;i++) {
      cin >> ropes[i];
   }

   cout<<"The Minimu Cost to Join All Ropes : "<<minCost(ropes)<<endl;

   return 0;

}