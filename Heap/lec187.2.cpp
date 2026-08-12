/* Heapify -> placing the given node at its correct position & building heap through heapify */

#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int>&arr,int n,int i) {
                          
    int leftChildIndex = 2*i;
    int rightChildIndex = 2*i + 1;
    int largestIndex = i;               // taking parent index as  largest value's index

    if(leftChildIndex <= n && arr[leftChildIndex] > arr[largestIndex]) {                // updating the largest value's index
        largestIndex = leftChildIndex;
    }

    if(rightChildIndex <= n && arr[rightChildIndex] > arr[largestIndex]) {
        largestIndex = rightChildIndex;
    }

    if(largestIndex != i) {
        swap(arr[i],arr[largestIndex]);      // placing the node at its correct position if above 3-condition satisfies
        heapify(arr,n,largestIndex);
    }

}

void builHeap(vector<int>&arr,int n) {

    for(int i=n/2;i>0;i--) {      // here , all leaf nodes index will be after n/2 , so need to touch them as they satisfies the heap condition
        heapify(arr,n,i);
    }

}

void heapSort(vector<int>&arr,int n){
    while(n > 1) {
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
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

    cout<<"Sorted : ";
    for(auto val : arr) {
        cout<<val<<" ";
    }

    return 0;

}