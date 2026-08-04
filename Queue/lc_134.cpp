/* Circular Tower Will be same Have Same Question */

/* we given with no .of gas stations in circular loop and to go from ith gas station to i+1th gas station -> we have cost[i] gas 
   so for 1 gas we can move 1 unit ahead  , so find the index of gas station from which we can start and come to same gas station 
   with given amount of costs 
*/

#include<bits/stdc++.h>
using namespace std;

/* Approach 1 : brute Force => we take every station's gas + gas from previous station and will check => can we go further ?
                ||   T.C : O(n^2)    ||    S.C : O(1)   ||
*/
int solve(vector<int>&gas,vector<int>&costs) {
    
    int start = 0;                // this pointer will trace the index of first while loop
    int available;                // this will check available(gas[i] + transferred gas from previous station)

    int n = gas.size();
    while(start < n) {

        available = 0;
        int i = start;

        while(available + gas[i] >= costs[i]) {         // if avaiable gas at ith station is greater than the ith costs
            available += gas[i] - costs[i];             // then consume cost[i] from available & update the available for (i+1)th station
            i = (i+1)%n;                         // this is will make sure for circular movement throughout the array
            if(i == start) return start;       // while traversing -> if i becomes start => means completed one circle => return the index
        }

        start++;                       // otherwise check for next indexes
    }
    return -1;
}

/* Appraoch 2 : Suppose if gas available  at ith station  is less  than costs[i] ? then we should start with i+1 index not with next to start pointer */
/* WHY ?  => basic e.g : if you have 5 rupee and want to buy 7 rupees item -> then someone should give 2 rupee more ( >=0 )
  similarly , if previouses gas stations is not adding something to ith gas , then you should start with next index
               ||     T.C : O(n)      ||      S.C : O(1)     ||
*/

int solve1(vector<int>&gas,vector<int>&costs) {
    
    int start = 0;                
    int available;                

    int n = gas.size();
    while(start < n) {

        available = 0;
        int i = start;
        int count = 0;

        while(available + gas[i] >= costs[i]) {         
            available += gas[i] - costs[i];             
            i = (i+1)%n;  
            count++;                      
            if(count == n) return start;      // one rotation will be completed when count will equal to length 
        }

        if(i < start) return -1;    // if criteria doesn't meet WHILE ROTATION => i will be less than start
        start =  i + 1;         // other wise start from very next index

    }

    return -1;
}

/* Appraoch 3 : Greedy Approach => e.g if we require x gas from 0th to ith => if extra x amount gas is available after consuming their respective
                                       cost from (i+1)th to n => then i+1 will be valid inde
so we will keep the track of the required gas => if any furter index till circular traversal complete this 
                               ||   T.C : O(n)    ||    S.C : O(1)
*/
int solve2(vector<int>&gas,vector<int>&costs) {

    int balance = 0;        // how much we are left with after consuming the cost
    int deficit = 0;        // how much will be required
    int n = gas.size();

    int start = 0;         // starting index from loop 
    for(int i=0;i<n;i++) {

        balance += gas[i] - costs[i];
        if(balance < 0) {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0) {
        return start;
    }

    return -1;

}

int main () {

    int n;
    cout<<"Enter The NO. of Gas stations : ";
    cin>>n;

    vector<int>gas(n);
    cout<<"Enter The Gas at Each Station : ";
    for(int i=0;i<n;i++) {
        cin>>gas[i];
    }

    vector<int>costs(n);
    cout<<"Enter The Cost : ";
    for(int i=0;i<n;i++) {
        cin>>costs[i];
    }

    cout<<"The Order Of Gas Station : "<<solve(gas,costs)<<endl;
    cout<<"The Order Of Gas Station : "<<solve1(gas,costs)<<endl;
    cout<<"The Order Of Gas Station : "<<solve2(gas,costs)<<endl;

    return 0;

}