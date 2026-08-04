/* Impelementing Doubly Ended Queue */

#include<iostream>
using namespace std;

class Deque {

    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data) {
        if((front == 0 && rear == size - 1) || ((rear - front) == -1)) {
            cout<<"Circular Queue is Full "<<endl;
            return;
        }
        else if(front == -1 ){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size -1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data) {
        
        if((front == 0 && rear == size - 1) || ((rear - front) == -1)) {
            cout<<"Circular Queue is Full "<<endl;
            return;
        }
        else if(front == -1 ){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(front == 0 && rear != size - 1){
            front = size - 1;
        }
        else{
            front--;
            arr[front] = data;
        }
    }

    void popFront() {
         if(front == -1){
            cout<<"Queue Is Empty !!"<<endl;
            return;
        }
        else if(front == rear) {
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
    }

    void popRear() {
        if(front == -1 && rear == -1) {
            cout<<"Empty Queue !!"<<endl;
            return;
        }
        else if(front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

};

int main() {

    Deque dq(10);

    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushRear(30);
    dq.pushFront(40);

    dq.popFront();
    dq.popRear();

    return 0;
}