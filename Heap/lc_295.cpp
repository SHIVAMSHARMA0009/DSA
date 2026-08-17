/* implement the median findder in continuous data stream */

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {                     //  -----MAX_HEAP_-- | ------MIN_HEAP---    => eg : 1 2 3 4 | 5 6 7 8     -> 4 is largest & 5 is smallest

    public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    double median;

    MedianFinder() {
        this->median = 0;
    }

    void addNum(int num){

        if(maxHeap.size() == minHeap.size()) {    // if size are equal -> so , after insertion size will become unequal , therefore top of greater size heap will give median

            if(num > median) {           // if num is greater then insert at right   
                minHeap.push(num);
                median = minHeap.top();  
            }
            else {
                maxHeap.push(num);           // if num is smaller then insert at left
                median = maxHeap.top();
            }
        }

        else if(maxHeap.size() == minHeap.size()+1){    // if size of max_heap greater than min_heap -> so after insertion size will become equal , average of tops will give the median

            if(num > median) {   // if num is greater then insert at right
                minHeap.push(num);             
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
            else{           // if num is smaller then insert at left -> but left is already large , so offload one element from left to right
                int val = maxHeap.top();
                maxHeap.pop();
                minHeap.push(val);
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
        }

        else if(maxHeap.size()+1 == minHeap.size()){    // if size of min_heap greater than max_heap -> so after insertion size will become equal , average of tops will give the median

            if(num > median) {           // if num is greater then insert at right -> but right is already large , so offload one element from right to left
                int val = minHeap.top();
                minHeap.pop();
                maxHeap.push(val);
                minHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
            else{              // if num is smaller then insert at left
                maxHeap.push(num);
                median = (minHeap.top() + maxHeap.top())/2.0;
            }
        }

    }

    double findMedian() {
        return median;
    }
};

int main() {

    MedianFinder m;
    
    m.addNum(4);
    cout<<"The Median : "<<m.findMedian()<<endl;

    m.addNum(3);
    cout<<"The Median : "<<m.findMedian()<<endl;

    m.addNum(3);
    m.addNum(1);
    m.addNum(8);
    m.addNum(7);
    m.addNum(5);
    m.addNum(6);
    m.addNum(9);
    m.addNum(2);    // 1 2 3 3 4 5 6 7 8 9  => (4+5)/2 : 4.5

    cout<<"The Median : "<<m.findMedian()<<endl;

    return 0;

}