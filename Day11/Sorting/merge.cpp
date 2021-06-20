//divie and conquear algorithm first divide into two halves and then merge them
//inplace no
//stable
//s.c o(n) t.c. o(nlogn)

/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        merge sort implementation
=============================================================================*/
#include<iostream>
using namespace std;

void merge(int arr[],int l,int r,int m);
void mergeSort(int arr[],int l,int r){
    if(l>=r)
    return;
    int m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,r,m);
}
void merge(int arr[],int l,int r,int m){
int n1=m-l+1,n2=r-m;

int* L=new int[n1];
int* R=new int[n2];

for(int i=0;i<m-l+1;i++)
L[i]=arr[l+i];

for(int i=0;i<r-m;i++)
R[i]=arr[m+i+1];

int li=0,ri=0;
int k=l;
while(li<n1 && ri<n2){
    if(L[li]>R[ri])
    arr[k++]=R[ri++];
    else
    arr[k++]=L[li++];
}
while(li<=m-l){
    arr[k++]=L[li++];
}
while(ri<=r-m-1){
    arr[k++]=R[ri++];
}
}



int main(){ 
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    mergeSort(arr, 0, n-1); 
    cout << "Sorted array: \n"; 
    for(auto x:arr)
    cout<<x<<" ";
    return 0; 
} 