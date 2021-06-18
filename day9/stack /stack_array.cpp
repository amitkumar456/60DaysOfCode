/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Implementation of Stack using array
=============================================================================*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
    int top;

public:
    int* arr=new int[MAX];

    Stack() {top=-1;};
    bool push(int x);
    int  peek();
    int  pop();
    bool isEmpty();
    bool isFull();
    void deleteStack();

};

bool Stack::push(int x){
if(isFull())
return false;
else
arr[++top]=x;
return true;
}

int Stack::peek(){
if(isEmpty())
return INT_MIN;
else
return arr[top];
}

int Stack::pop(){
if(isEmpty())
return INT_MIN;
else{
    int temp=arr[top--];
    return temp;
}
}

bool Stack::isEmpty(){
return (top<0);
}

bool Stack::isFull(){
return (top>=MAX-1);
}
void Stack::deleteStack(){
arr=NULL;
}


int main() {
    
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.pop()<< " Popped from stack\n";

    cout<<" Element Present in Stack: ";

    while(!s.isEmpty()){
    
    cout<<s.peek()<<" ";
    s.pop();
    }
      
    
     return 0;
}
