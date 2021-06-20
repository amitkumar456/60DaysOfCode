/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        bubble sort implementation
=============================================================================*/


//adjacent element swap
//tc [worst and averageo](n^2) best tc o(n) if array is already sorted
//no extra space is required, stable , inplace
//used for detect very small error like (just swap 2 elements) in almost sorted array in o(n) t.c.

#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[],int n){

for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1])
        swap(&arr[j],&arr[j+1]);
    }
}
}
int main(){ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    cout<<"Sorted array: \n"; 
    for(auto x:arr)
    cout<<x<<" ";
    return 0; 
} 
