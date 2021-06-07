/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Maximum index
=============================================================================*/
#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int max(int a,int b){
    return a>b? a:b;
}
//approach 1 brute force
//t.c. o(N^2) s.c. (1)
int maxindexDiff(int arr[],int n){
int diff=-1;
for(int i=0;i<n-1;i++){
    for(int j=n-1;j>=i;j--){
        if(arr[i]<=arr[j]){
            diff=max(j-i,diff);
        }
         
    }
}
int binary_search(int arr[],int start,int end,int k){
if(i>j)
return -1;
int mid=(start+end)/2;
else if(arr[mid]==k)
return k;
else if(arr[mid]>k)
return binary_search(arr,start,mid-1,k);
else
return binary_search(arr,mid+1,start,k);
}
//approach 2 using bud optimization
//t.c. o(Nlogn) s.c. o(N) .
int maxindexDiff(int arr[],int n){
    vector<int> v(n+1,INT_MIN);
    for(int i=n-1;i>=0;i--){
        v[i]=max(v[i+1],arr[i])
    }
    int result=0;
    for(int i=0;i<n;i++){
        int low=i+1,high=n;ans=i;

        while(low<=high){
            int mid=(low+high)/2;

            if(arr[i]<=v[mid]){
                ans=max(ans,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        result=max(result,ans-i);
        
    }
    return diff;
}
//approach 3 using hashing and sorting
int maxindexDiff(int arr[],int n){
    
    unordered_map<int,vector<int>> hashmap;

    for(int i=0;i<n;i++){
    hashmap[arr[i]].push_back(i);
    }
    sort(arr,arr+n);
    int maxDiff=INT_MIN;
    int temp=n;

    //iterate from 0 to n-1
    for(int i=0;i<n;i++){
        if(temp>hashmap[arr[i][0]]){
            temp=hashmap[arr[i]][0];
        }
        maxDiff=max(maxDiff,hashmap[arr[i]][hashmap[arr[i].size()-1]-temp);

    }
    return maxDiff;

}

//approach 4 effiecient
int maxindexDiff(int arr[],int n){
    int maxDiff;
    int i,j;
    int* LMin=new int[sizeof(int)*n];
    int* RMax=new int[sizeof(int)*n];
    
    LMin[0]=arr[0];
    for(int i=1;i<n;i++)
     LMin[i]=min(arr[i],Lmin[i-1]);
    
    RMax[n-1]=arr[n-1];
    for(j=n-2;j>=0;j--)
     RMax[j]=max(arr[j],RMax[j+1]);
    
    i=0,j=0,maxDiff=-1;
    while(j<n && i<n){
        if(LMin[i]<RMax[j]){
            maxDiff=max(maxDiff,j-i);
            j=j+1;
        }
        else
        i=i+1;
    }
    return maxDiff;
}
int main() {
    
     int arr[]={34,8,10,3,2,80,30,33,1};
     int n=sizeof(arr)/sizeof(arr[0]);
     cout<<maxindexDiff(arr,n)<<endl;
    
     return 0;
}
