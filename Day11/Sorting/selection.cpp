//find minimum in unsorted array and put it in beggining
//t.c. o(n^2) s.c. o(1)
//useful when memory writing is costly just make n swap in entire alog
//not stable
//stable by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal key or by tweaking it in a way such that its meaning doesn’t change and it becomes stable as well.

/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        selection sort implementation
=============================================================================*/

#include<iostream>
using namespace std;

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[],int n){

    for(int i=0;i<n;i++){
        int imin=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[imin])
             imin=j;
        }
        swap(&arr[imin],&arr[i]);
    }
}

int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    for(auto x:arr)
    cout<<x<<" ";
    return 0; 
} 
