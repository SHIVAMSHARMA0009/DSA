/* Heapify -> placing the given node at its correct position & building heap through heapify */

#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int>&arr,int n,int i) {

    int parentIndex = i;                          
    int leftChildIndex = 2*i;
    int rightChildIndex = 2*i + 1;
    int largestIndex = parentIndex;               // current taking parent index as  largest value's index

    if(leftChildIndex <= n && arr[leftChildIndex] > arr[parentIndex]) {                // upadating the largest value's index
        largestIndex = leftChildIndex;
    }

    if(rightChildIndex <= n && arr[rightChildIndex] > arr[parentIndex]) {
        largestIndex = rightChildIndex;
    }

    if(largestIndex != parentIndex) {
        swap(arr[parentIndex],arr[largestIndex]);      // placing the node at its correct position if aobe 3-condition satisfies
        parentIndex = largestIndex;
        heapify(arr,n,parentIndex);
    }

}

void builHeap(vector<int>&arr,int n) {

    for(int i=n/2;i>0;i--) {      // here , all leaf node index will be after n/2 , so need to touch them  as they satisfies the heap condition
        heapify(arr,n,i);
    }

}

int main() {

    int n;
    cout<<"Enter Array Size : ";
    cin>>n;

    vector<int>arr(n+1);
    cout<<"Enter The Array Value : ";
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    builHeap(arr,n);

    cout<<"The Heap Formation : ";
    for(auto val :  arr) {
        cout<<val<<" ";
    }

    return 0;

}