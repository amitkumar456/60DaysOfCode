/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Wave array
=============================================================================*/
#include<iostream>
using namespace std;
class Solution{
    public:
    void swap(int* a,int* b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    //t.c. o(nlogn) if sorted array is not given
    void convertToWave_1(int *arr,int n){
    for(int i=0;i<n-1;i=i+2){
        swap(&arr[i],&arr[i+1]);
    }
    }
    void convertToWave_2(int *arr,int n){
        for(int i=0;i<n;i++){

            if(i>0 && arr[i-1]>arr[i])
             swap(&arr[i],&arr[i-1]);
            if(i<n-1 && arr[i]<arr[i+1])
             swap(&arr[i],&arr[i+1]);
        }
    }

};
int main() {
    
     int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     Solution obj;
     obj.convertToWave(arr,n);
     for(auto a:arr)
     cout<<a<<" ";

    
     return 0;
}
