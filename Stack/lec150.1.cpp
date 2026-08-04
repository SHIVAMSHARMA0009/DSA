/* taking two stack implementation through array */

#include<iostream>
using namespace std;

class Stack{

    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }


    // functions
    void push1(int data){
        if(top2 - top1 == 1){
            cout<<"No Space Available in stack 1 "<<endl;
        }
        else{
            arr[++top1] = data;
        }
    }

    void push2(int data){
        if(top2 - top1 == 1){
            cout<<"No Space Available in stack 2 "<<endl;
        }
        else{
            arr[--top2] = data;
        }
    }

    void pop1(){
       if(top1 == -1){
        cout<<"Underflow , stack 1 is empty"<<endl;
       }
       else{
        top1--;
       }
    }

    void pop2(){
       if(top2 == size){
        cout<<"Underflow , stack 2 is empty"<<endl;
       }
       else{
        top2++;
       }
    }

    bool isEmpty1(){
        if(top1 == -1){
            return true;
        }
        return false;
    }

    bool isEmpty2(){
        if(top2 == size){
            return true;
        }
        return false;
    }

    int gettop1(){
        if(top1 == -1){
            cout<<"There is not element in stack 1"<<endl;
        }
        return arr[top1];
    }

    int gettop2(){
        if(top2 == size){
            cout<<"There is not element in stack 2"<<endl;
        }
        return arr[top2];
    }


};

int main(){

    Stack s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);

    s.push2(110);
    s.push2(220);
    s.push2(330);
    s.push2(440);

    s.pop1();
    s.pop2();

    while(!s.isEmpty1() || !s.isEmpty2()) {
        if(!s.isEmpty1()) {
            cout << s.gettop1() << " ";
            s.pop1();
        }
        if(!s.isEmpty2()) {
            cout << s.gettop2() << " ";
            s.pop2();
        }
    }


    return  0;
}