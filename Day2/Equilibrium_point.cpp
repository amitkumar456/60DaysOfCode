/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Equilibrium point
=============================================================================*/
#include<iostream>
using namespace std;
class Solution{
    public:
    //using brute force t.c. o(n^2) s.c. o(1)
    int equilibriumPoint_1(int a[],int n){
        int i,j;
        for(i=1;i<n-1;i++){
            int sum1=0,sum2=0;
            for(j=0;j<i;j++)
             sum1+=a[j];
             for(j=i+1;j<n;j++)
             sum2+=a[j];
             if(sum1==sum2)
             return i+1;
        }
        return -1;
    }

    //approach 2 t.c. o(n) s.c. o(1)
    int equilibriumPoint_2(int a[],int n){
    if(n==1)
    return 1;
    int sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    int leftsum=0;
    for(int i=0;i<n;i++){
     sum-=a[i];
     if(sum==leftsum)
     return i+1;
     leftsum+=a[i];
    }
    return -1;

    }

    //approach 3 t.c. o(n) s.c. o(n) 
    //using prefix and suffix array
    int equilibriumPoint_3(int arr[],int n){
        int prefixSum[n];
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++)
         prefixSum[i]=prefixSum[i-1]+arr[i];
        
        int suffixSum[n];
        suffixSum[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
         suffixSum[i]=suffixSum[i+1]+arr[i];

        for(int i=0;i<n;i++){
            if(suffixSum[i]==prefixSum[i])
             return i++;
        }
        return -1;
    }
    //approach 4 t.c. o(n) s.c. o(1)
    //using two pointer algorithm
    int equilibriumPoint_4(int arr[],int n){
        int i=0;
        int left_sum=0;
        int j=n-1;
        int right_sum=0;
        for(i,j;i<n,j>=0;i++,j--){
            left_sum+=arr[i];
            right_sum+=arr[j];
            while(left_sum<right_sum && i<j){
                i++;
                left_sum+=arr[i];
            }
            while(left_sum>right_sum && i<j){
                j++;
                right_sum+=arr[j];
            }
            if(left_sum==right_sum && i==j)
            return i;
        }
        return -1;
    }

};
int main() {
    
     int arr[]= {1,3,5,2,2};
     int n=sizeof(arr)/sizeof(arr[0]);
     Solution obj;
     cout<<obj.equilibriumPoint_1(arr,n)<<endl;
    
     return 0;
}
