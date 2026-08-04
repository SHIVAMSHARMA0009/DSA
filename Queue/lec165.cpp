/* implementation of queue using array */

#include<iostream>
using namespace std;

class Queue {

    public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size) {
        arr = new int[size];
        this->size = size;
        front = 0;            
        rear = 0;              
    }

    // Pushing 
    void push(int data) {                    
        if(rear == size) {                      // queue is full if rear is equal to size
            cout<<"Queue is Full !!"<<endl;
        }
        else{                                  // otherwise push data at rear
            arr[rear++] = data;
        }
    }

    void pop() {
        if(front == rear) {                    // if front and rear are equal means queue is empty
            cout<<"Queue is Empty !!"<<endl;
        }
        else{
            front++;                     // otherwise move front
            if(front == rear) {  // suppose front and rear equal means queue is empty
                front = 0;      // pushing of element should start from starting only 
                rear = 0;
            }
        }
    }

    int getfront() {
        if(front == rear) {                // means queue is empty
            cout<<"Empty Queue !!";
            return -1;
        }
        return arr[front];          // element at front
    } 

    bool empty() {
        return front == rear;       // condition for empty queue
    }

    int getSize() {                  // size of queue at the moment
        return rear - front;
    }

};

int main() {

    Queue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout<<"Size Of Queue : "<<q.getSize()<<endl;


    q.pop();

    cout<<"Size Of Queue : "<<q.getSize()<<endl;

    cout<<"Front Element : "<<q.getfront()<<endl;

    if(q.empty()) {
        cout<<"Q is Empty"<<endl;
    }
    else{
        cout<<"Q is not Empty"<<endl;
    }

    return 0;

}