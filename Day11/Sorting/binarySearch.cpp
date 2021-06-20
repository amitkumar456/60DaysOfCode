/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        binary Search implementation using recursive as well as iterative method
=============================================================================*/
#include<iostream>
using namespace std;
//recursive approach
int binarySearch(int arr[],int l,int r,int x){
if(l>r)
return -1;
int m=l+(r-l)/2;
if(arr[m]==x)
return m;
else if(arr[m]>x)
return binarySearch(arr,l,m-1,x);
else
return binarySearch(arr,m+1,r,x);
}
//iterative approach
int binarySearch2(int arr[],int l,int r,int x){
while(l<=r){
int m=l+(r-l)/2;
if(arr[m]==x)
return m;
else if(arr[m]>x)
r=m-1;
else
l=m+1;
}
return -1;
}
int main(void){
    int arr[] = { 2, 3, 4, 10, 40 ,50};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch2(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}