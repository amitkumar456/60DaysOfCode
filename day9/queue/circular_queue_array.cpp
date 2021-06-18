/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Circular Queue implementation using array
=============================================================================*/
#include<iostream>
#include<climits>
using namespace std;

class Queue{
    int front, rear,size;
    int *array;
public:
    Queue(unsigned capacity);
    void enqueue(int x);
    int  dequeue();
    int  peek();
    bool isEmpty();
    bool isFull();
    void deleteQueue();
};
Queue::Queue(unsigned capacity){
    front=-1;
    rear=-1;
    size=capacity;
    array=new int[size];
}
void Queue::enqueue(int x){
    if(isFull())
     return;
    else if(isEmpty())
     front++;
    
    else if(rear==size-1){
        rear=0;
        array[rear]=x;
        return;
    }
    array[++rear]=x;
}

int Queue::dequeue(){
if(isEmpty())
return INT_MIN;
int temp=array[front];
if(front==rear){
    front=-1;
    rear=-1;
}
else{
    if(front==size-1)
    front=0;
    else
    front++;
}
return temp;
}
int Queue::peek(){
if(isEmpty())
return INT_MIN;
else
return array[front];
}
bool Queue::isEmpty(){
return (front==-1 || rear==-1);
}
bool Queue::isFull(){
if(front ==0 && rear== size-1)
return true;
else if(front-rear==1)
return true;
return false;
}
void Queue::deleteQueue(){
front=-1;
rear=-1;
array=NULL;
}

int main() {
    
    Queue queue(5);
    cout<<"enqueuing 5 values\n";
    for(int i=1;i<=5;i++){
        queue.enqueue(10*i);
    }

    cout<<"peek values after enqueue\n";
    cout<<queue.peek()<<"\n";

    queue.enqueue(60);
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(60);
    cout<<"peek values after enqueue 60 :"<<queue.peek()<<endl;


    for(int i=0;i<4;i++){

        cout<<queue.peek()<<"\n";
        queue.dequeue();

     }

      
    
     return 0;
}
