/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Queue implementation using Linked List
=============================================================================*/
#include<iostream>
#include<climits>
using namespace std;

struct QueueNode{
    int data;
    QueueNode* next;
    QueueNode(int x){data=x;next=NULL;};
};
class Queue{
    QueueNode *head, *tail;
public:
    Queue();
    void enqueue(int x);
    int  dequeue();
    int  peek();
    bool isEmpty();
    bool isFull();
    void deleteQueue();
};

Queue::Queue(){
    head=NULL;
    tail=NULL;
}
void Queue::enqueue(int x){
QueueNode *temp=new QueueNode(x);
if(!head){
    head=temp;
    tail=temp;
}
else{
    tail->next=temp;
    tail=temp;
}
}
int  Queue::dequeue(){
if(!head)
return INT_MIN;
int val=head->data;
if(!head->next)
tail=NULL;
head=head->next;
return val;
}
int Queue::peek(){
if(!head)
return INT_MIN;
return head->data;
}
bool Queue::isEmpty(){
return (!head);
}
void Queue::deleteQueue(){
head=NULL;
tail=NULL;
}

int main() {
     Queue queue;
    cout<<"enqueuing 6 values\n";
    for(int i=1;i<=6;i++){
        queue.enqueue(10*i);
    }

    cout<<"peek values after enqueue\n";
    cout<<queue.peek()<<"\n";

    cout<<"Front item is :"<<queue.peek()<<endl;

    while(!queue.isEmpty()){

        cout<<queue.peek()<<"\n";

        queue.dequeue();
    }
      
    
     return 0;
}
