/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Kadane's Algorithm
=============================================================================*/
#include <iostream>
#include <climits>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
//approach 1 brute force t.c. o(N^2) s.c. o(1)
int maxSubarraySum(int arr[], int n){
    int sum_global = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[i];
            if (sum > sum_global)
                sum_global = sum;
        }
    }

    return sum_global;
}
//approach 2 divide and conquer technique
int maxSubarraySum_2(int arr[],int n){
int sum_global=arr[0];
int sum_current=arr[0];
for(int i=1;i<n;i++){
    sum_current=max(arr[i]+sum_current,arr[i]);
    if(sum_global<sum_current)
    sum_global=sum_current;
}
return sum_global;
}
int main(){

    int arr[] = {1, 2, 3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubarraySum_2(arr, n) << endl;

    return 0;
}
