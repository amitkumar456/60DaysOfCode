/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Queue implementation using array
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
    array=new int[capacity];

}
void Queue::enqueue(int x){
    if(isFull())
     return;
    else if(isEmpty())
    front++;   
    array[++rear]=x;
}

int Queue::dequeue(){
if(isEmpty())
return INT_MIN;
int temp=array[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}
int Queue::peek(){
if(isEmpty())
return INT_MIN;
else
return array[front];
}
bool Queue::isEmpty(){
return (front==-1);
}
bool Queue::isFull(){
return (rear==size-1);
}
void Queue::deleteQueue(){
front=rear=-1;
array=NULL;
}

int main() {
    
    Queue queue(5);
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
