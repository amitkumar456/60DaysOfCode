//divide and conquear alogrithm at each step it find pivot and make sure that smaller element left of pivot and bigger element right of pivot
//worst case when pivot picks smallest or largest element(o(n*2))
//inplace(only uses recursive call)
//notstable
//best case when pivot always picks middle element o(*nlogn)

/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        quick sort and random quick sort algortihm
=============================================================================*/
#include<iostream>
#include<random>

using namespace std;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int l,int r);
int partition_r(int arr[],int l,int r);
void quickSort(int arr[],int l,int r){
if(l>=r)
return;
int p=partition_r(arr,l,r);
quickSort(arr,l,p-1);
quickSort(arr,p+1,r);

}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    int j=l;
    while(j<r){
        if(pivot>arr[j]){
        i++;
        swap(&arr[i],&arr[j]);
    }
    j++;
    }
    i++;
    swap(&arr[i],&arr[r]);
    return i;
}

int partition_r(int* arr,int l,int r){
    int p=l+rand()%(r-l);
    swap(&arr[p],&arr[r]);
    return partition(arr,l,r);
}


int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    cout << "Sorted array: \n"; 
    for(auto x:arr)
    cout<<x<<" ";
    return 0; 
} 