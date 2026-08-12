/* we have to insert the value in (max) heap with the help of array */

 #include<bits/stdc++.h>
 using namespace std;

 class Heap {

    public:
    int *arr;
    int size;
    int index;

    Heap (int size) {
        arr = new int[size + 1];    // bcz we are starting with index 1
        this->size = size;
        this->index = 0;
    }

    void print() {
        for(int i=1;i<=index;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    void insert(int value) {

        if(index >= size) {                     // if index exceed the capacity
            cout<<"Heap Overflow"<<endl;
            return;
        }

        index = index + 1;
        int childIndex = index;                // place value at last node
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

 };

 int main() {

    int size;
    cout<<"Enter The Heap Size : ";      // the original heap capacity 
    cin>>size;
    Heap h(size);

    int n;
    cout<<"Enter No .of Values : ";    // the no.of value we want to insert
    cin>>n;

    cout<<"Enter Value : ";
    for(int i=1;i<=n;i++) {     // inserted 5 values
        int val;
        cin>>val;
        h.insert(val);
    }
    
    cout<<"The Max Heap : ";    
    h.print();

    h.insert(110);               // 6th
    cout<<"The Max Heap : ";
    h.print();

    h.insert(210);               // 7th
    cout<<"The Max Heap : ";
    h.print();

    h.insert(310);               // 8th
    cout<<"The Max Heap : ";
    h.print();

    h.insert(410);                   // 9th overflow-condition
    cout<<"The Max Heap : ";
    h.print();

    return 0;

 }