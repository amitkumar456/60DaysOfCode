/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        binary heap implementation by array
=============================================================================*/
#include<iostream>
#include<climits>
using namespace std;
class binaryHeap{
int size;
int* arr;
public:
    binaryHeap(int capacity);
    int peek();
    int extractMax();
    void insert(int x);
    void deleteHeap();
    void heapifyBottomToTop(int i);
    void heapifyTopToBottom(int i);
    void levelOrder();
};
binaryHeap::binaryHeap(int capacity){
  size=0;
  arr=new int[capacity+1];
}
int binaryHeap::peek(){
    if(!size)
     return INT_MIN;
    return arr[1];
}
void binaryHeap::insert(int x){
arr[++size]=x;
heapifyBottomToTop(size);
}
int binaryHeap::extractMax(){
if(!size)
return INT_MIN;
int temp=arr[1];
arr[1]=arr[size--];
heapifyTopToBottom(1);
return temp;
}
void binaryHeap::deleteHeap(){
arr=NULL;
}
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int max(int a,int b){
    return (a>b)? a:b;
}
void binaryHeap::heapifyBottomToTop(int i){
if(i<=1)
return;
int parent=i/2;

if(arr[parent]<arr[i]){
swap(&arr[parent],&arr[i]);
}
heapifyBottomToTop(parent);
}


void binaryHeap::heapifyTopToBottom(int i){
int left=2*i;
int right=2*i+1;
int largest;
if(left>size)
return;
if(left==size){
    if(arr[i]<arr[left])
     swap(&arr[i],&arr[left]);
     return;
}
else{
    if(arr[right]<arr[left])
    largest=left;
    else
    largest=right;
    if(arr[largest]>arr[i])
    swap(&arr[largest],&arr[i]);
}
heapifyTopToBottom(largest);
return;

}
void binaryHeap::levelOrder(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    
     binaryHeap bh(10);
     for(int i=0;i<10;i++){
         bh.insert(10*i);
     }

     bh.levelOrder();
     cout<<bh.extractMax()<<"\n";
     bh.insert(5);
     bh.levelOrder();

     cout<<bh.extractMax()<<"\n";
     bh.levelOrder();
     return 0;
}
