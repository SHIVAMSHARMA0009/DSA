/* Implementing circular queue using array */

#include<iostream>
using namespace std;

class CirQueue {

    public:
    int *arr;
    int front;
    int rear;
    int size;

    CirQueue(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;            
        rear = -1;              
    }

    // Pushing 
    void push(int data) {                    
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

    void pop() {
        if(front == -1){
            cout<<"Queue Is Empty !!"<<endl;
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

};

int main() {

    CirQueue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    return 0;

}