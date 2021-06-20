//divide the array in sorted and unsorted then pick first element in unsorted and put correct position in sorted array
//t.c. o(n^2) s.c. o(1) 
//boundary case isort take max time when sorted in reverse order
//best case when array is already sorted
//inplace stable

/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        insertion sort implementation
=============================================================================*/

#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int arr[],int n){

    for(int i=1;i<n;i++){
        int j=i;
        while(arr[j-1]>arr[j] && j>0){
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }
}

int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    insertionSort(arr, n); 
    cout << "Sorted array: \n"; 
    for(auto x:arr)
    cout<<x<<" ";
    return 0; 
} 