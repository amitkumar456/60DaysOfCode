/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        implemenation of stack using linked list
=============================================================================*/

/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Stack implementation using Linked List
=============================================================================*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct stackNode{
    int data;
    stackNode* next;
    stackNode(int x){data=x;next=NULL;};
};

class Stack{
   stackNode* head;
public:

    Stack() {head=NULL;};
    void push(int x);
    int  peek();
    int  pop();
    bool isEmpty();
    // bool isFull();
    void deleteStack();

};

 void Stack::push(int x){
 stackNode* temp=new stackNode(x);
 temp->next=head;
 head=temp;
 
 }
 int  Stack::peek(){
 if(isEmpty())
  return INT_MIN;
 return head->data;
 }
 int  Stack::pop(){
 if(isEmpty())
  return INT_MIN;
 else{
     int x=head->data;
     head=head->next;
     return x;
 }

 }
 bool Stack::isEmpty(){
 return (head==NULL);
 }
 void Stack::deleteStack(){
 head=NULL;
 }


int main(){

    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.pop()<<" popped from stack\n";

    cout << "Top element is " << s.peek() << endl;
     
    cout<<"Elements present in stack : ";

    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}