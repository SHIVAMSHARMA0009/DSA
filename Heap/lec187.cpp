/* we have to insert & delete the value in (max) heap with the help of array */

 #include<bits/stdc++.h>
 using namespace std;

 class Heap {

    public:
    int *arr;
    int capacity;
    int size;

    Heap (int capacity) {
        arr = new int[capacity + 1];    // bcz we are starting with index 1
        this->capacity = capacity;
        this->size = 0;
    }

    void print() {
        for(int i=1;i<=size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    // T.C : O(logn)
    void insert(int value) {

        if(size >= capacity) {                     // if index exceed the capacity
            cout<<"Heap Overflow"<<endl;
            return;
        }

        size = size + 1;
        int childIndex = size;                // place value at last node
        arr[childIndex] = value;

        while(childIndex > 1) {

            int parentIndex = childIndex/2;            // now place value at its right index so that max property remains

            if(arr[childIndex] > arr[parentIndex]) {
                swap(arr[childIndex],arr[parentIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }

    }


    // T.C : O(logn)
    void remove() {

        //  replace the root node with last node
        arr[1] = arr[size];
        size--;

        // place root node at its correct position
        int curr_index = 1;                              // index of root 
        while(curr_index < size) {

            int leftChildIndex = 2*curr_index;            
            int rightChildIndex = 2*curr_index + 1;
            int largestVal_index = curr_index;

            if(leftChildIndex < size && arr[largestVal_index] < arr[leftChildIndex]) {     // checking which child is largest from its parent node and storing its index
                largestVal_index = leftChildIndex;
            }

            if(rightChildIndex < size && arr[largestVal_index] < arr[rightChildIndex]) {
                largestVal_index = rightChildIndex;
            }

            if(largestVal_index == curr_index) return;
            else {
                swap(arr[largestVal_index],arr[curr_index]);    // now replacing the root node at its right place
                curr_index = largestVal_index;
            }
        }
    }

 };

 int main() {

    int capacity;
    cout<<"Enter The Heap Size : ";      // the original heap capacity 
    cin>>capacity;
    Heap h(capacity);

    int size;
    cout<<"Enter No .of Values : ";    // the no.of value we want to insert
    cin>>size;

    cout<<"Enter Value : ";
    for(int i=1;i<=size;i++) {     // inserted 5 values
        int val;
        cin>>val;
        h.insert(val);
    }
    
    cout<<"The Max Heap : ";    
    h.print();

    h.insert(110);                              // 6th
    cout<<"The Max Heap after insertion : ";
    h.print();

    h.insert(210);                              // 7th
    cout<<"The Max Heap after insertion : ";
    h.print();

    h.insert(310);                               // 8th
    cout<<"The Max Heap after insertion : ";
    h.print();

    h.insert(410);                               // 9th overflow-condition
    cout<<"The Max Heap after insertion : ";
    h.print();

    h.remove();                                  // deletion
    cout<<"The Max Heap after deletion : ";
    h.print();



    return 0;

 }