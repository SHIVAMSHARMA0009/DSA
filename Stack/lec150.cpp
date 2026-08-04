/* Implementation of stack using the Array */

#include<iostream>
using namespace std;

class Stack{

    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }


    // functions
    void push(int data){

        if(size - top > 1){
            // space available
            top++;
            arr[top] = data;
        }
        else{
            // space not available
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top == -1){
            // stack is empty;
            cout<<"UnderFlow, can't delete element"<<endl;
        }
        else{
            // stack is not empty
            top--;
        }
    }

    int gettop(){
        if(top == -1){
            cout<<"There is not element in stack"<<endl;
        }
        return arr[top];
    }

    int getsize(){
        return top + 1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

};

int main(){

    //creation
    Stack s(10);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()){
        cout<<s.gettop()<< " ";
        s.pop();
    }

    cout<<"Size Of Stack : "<<s.getsize()<<endl;

    return 0;


}