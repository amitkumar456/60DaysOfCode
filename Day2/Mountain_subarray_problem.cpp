/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Mountain subarray problem
=============================================================================*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
     //approach 1 t.c. o(n*q) s.c. o(q)
     vector<bool> processQueries_1(int a[],int n,vector<pair<int,int>> &queries,int q){
     
     vector<bool> result;
     for(int i=0;i<q;i++){
     
        int  start=queries[i].first;
        int    end=queries[i].second;
        int      j=start;
        bool value=true;

    while(j<end && a[j]<=a[j+1]){
    j++;
    }
    while(j<end && a[j]>=a[j+1]){
    j++;
    }
    if(j!=end)
    value=false;
    result.push_back(value);
    }
    return result;
}
//approach 2 t.c. o(n+q) s.c. o(n)
    void preprocess(int a[],int n,int left[],int right[]){
    left[0]=0;
    int lastptr=0;
    for(int i=1;i<n;i++){
    if(a[i]>a[i-1])
    lastptr=i;
    left[i]=i;
    }
    right[n-1]=n-1;
    lastptr=n-1;
    for(int i=n-2;i>=0;i--){
    if(a[i]>a[i+1])
    lastptr=i;
    right[i]=lastptr;
    }
    }
bool isSubarrayMountainForm(int arr[], int left[],int right[],int L,int R){
    return left[R]>=right[L];
}

};
int main() {
     
     int a[]={4,3,1,2};
     int n=sizeof(a)/sizeof(a[0]);
     int q=2;
     vector<pair<int,int>> queries(q);
     queries.push_back(make_pair(0,2));
     queries.push_back(make_pair(1,3));
     Solution obj;
     auto v=obj.processQueries_1(a,n,queries,q);
     for(bool u:v){
     cout<< (u? "Yes\n":"No\n");
     }
     int left[n],right[n];
     obj.preprocess(a,n,left,right);
    
     return 0;
}
