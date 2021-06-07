/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Subarray with given sum
=============================================================================*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


//approach 1 brute force solution
//t.c. o(N^2) s.c. o(1)
vector<int> subarraySum(int arr[],int n,int s){
vector<int> list;

for(int i=0;i<n;i++){
    int curr_sum=arr[i];
    if(curr_sum==s){
        list.push_back(i+1);
        list.push_back(i+1);
        return list;
    }
    for(int j=i+1;j<n;j++){
    curr_sum+=arr[j];
    if(curr_sum==s){
        list.push_back(i+1);
        list.push_back(j+1);
        return list;
    }
    }
}
return {-1};
}

//approach 2
//sliding window technique
vector<int> subarraySum_2(int arr[],int n, int s){
    vector<int> list;
    int window_sum=0;
    int i=0;
    int j=0;
    while(i<n && j<n){
    if(window_sum<s){
    window_sum+=arr[j];
    j++;
    }
    else if(window_sum==s){
        list.push_back(i+1);
        list.push_back(j+1);
        return list;
    }
    else{
    window_sum-=arr[i];
    i++;
    }
    }
    return {-1};
}

//approach 3
//if our array contains negative number's
//t.c. o(n) s.c. o(1)
vector<int> subarraySum_3(int arr[],int n,int sum){
   unordered_map<int,int> map;
   vector<int> list;

   int curr_sum=0; 

   for(int i=0;i<n;i++){

       curr_sum=curr_sum+arr[i];

       if(curr_sum==sum){
           list.push_back(1);
           list.push_back(i+1);
           return list;
       }
       if(map.find(curr_sum-sum)!=map.end()){
           list.push_back(map[curr_sum-sum]+1);
           list.push_back(i);
           return list;
       }
       map[curr_sum]=i;
   }
}
//approach 4
//if our's array contains negative number's
//t.c. o(n) s.c. o(1)
vector<int> subarraySum_4(int arr[],int n,int sum){

int minEle=INT_MAX;

for(int i=0;i<n;i++)
minEle=min(arr[i],minEle);

int curr_sum=arr[0]+abs(minEle), start=0,i;

int targetSum=sum;

for(i=1;i<=n;i++){
    
    while(curr_sum-(i-start)*abs(minEle)>targetSum && start<i){
        curr_sum=curr_sum-arr[start]-abs(minEle);
        start++;
    }

    if(curr_sum-(i-start)*abs(minEle)==targetSum){
        cout<<start<<" "<<i-1;
        return ;
    }
    if(i<n){
        curr_sum=curr_sum+arr[i]+abs(minEle);
    }
}


return {-1};
}
int main() {
    
    int arr[]={1,2,3,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s=12;
    vector<int> v=subarraySum(arr,n,s);
    for(auto a:v)
    cout<<a<<" ";
    
     return 0;
}
