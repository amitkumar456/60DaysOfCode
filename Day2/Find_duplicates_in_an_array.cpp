/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Find duplicates in an array
=============================================================================*/
#include<iostream>
#include<vector>
using namespace std;


//approach 1 t.c. o(n) s.c. o(n)
vector<int> duplicates_1(int arr[],int n){
vector<int> v;
vector<int> hash(n,0);
for(int i=0;i<n;i++){
    hash[arr[i]]++;
}
for(int i=0;i<n;i++){
    if(hash[arr[i]]==2)
    v.push_back(arr[i]);
}
return v;
}
//approach 2 t.c. o(n) s.c. o(1)
//did a little bit optimization if number are o to n-1 and size of array is n then array can be used hash table directly.
vector<int> duplicates_2(int arr[],int n){
    for(int i=0;i<n;i++){
        int index=arr[i]%n;
        arr[index]+=n;
    }
    for(int i=0;i<n;i++){
        if((arr[i]/n)>=2)
        cout<<i<<" ";
    }
}
int main() {
    
     int arr[]={0,3,1,2,2};
     int n=sizeof(arr)/sizeof(arr[0]);
     vector<int> v=duplicates_1(arr,n);
     for(auto a:v)
     cout<<a<<" ";
    
     return 0;
}
