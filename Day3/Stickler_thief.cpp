/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Stickler Thief
=============================================================================*/
#include <iostream>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
//divie and conquer solution 
int FindMaxSum(int arr[],int n,int i){
    if (i >= n)
        return 0;
    return max(arr[i] + FindMaxSum(arr, n, i + 2), FindMaxSum(arr, n, i + 1));
}
//dynamic programming (overlapping subproblem) top down appproach
//t.c. o(n) s.c. o(n)
int dp[6];
int FindMaxSum_2(int arr[],int n,int i){

if(i>=n)
return 0;
if(dp[i]==0)
arr[i]=max(arr[i]+FindMaxSum_2(arr,n,i+2),FindMaxSum_2(arr,n,i+1));
return arr[i];
}
//dynamic programming(overlapping subproblem) bottom down approach
//t.c. o(n) s.c. o(1)
int FindMaxSum_2(int arr[],int n,int i){
    int *DP=new int[n+2];
    for(int i=n-2;i>=0;i++){
        DP[i]=max(arr[i]+DP[i+2],DP[i+1]);
    }
    return DP[0];
}

int main()
{

    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << FindMaxSum_2(arr, n, 0);

    return 0;
}
