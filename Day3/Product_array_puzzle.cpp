/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Product array puzzle
=============================================================================*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//usual solution but using division operation
//t.c. o(n) s.c. o(1)
int* productExceptSelf(int arr[],int n){
int pro=1;
int zero=0;
for(int i=0;i<n;i++){
    if(arr[i]==0)
    zero++;
    else
    pro*=arr[i];
}
for(int i=0;i<n;i++){
    if(zero>1)
     arr[i]==0;
    else if(arr[i]==0 && zero==1)
     arr[i]=pro;
    else if(arr[i]!=0)
     arr[i]=pro/arr[i];
}
return arr;
}



//method naive solution t.c. o(N) s.c. o(N)
//using prefix and suffix product
vector<int> productExceptSelf_1(int arr[],int n){
    vector<int> product;
    int prefix[n];
    int suffix[n];
    prefix[0]=1;
    suffix[n-1]=1;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*arr[i];
    }
    for(int j=n-2;j>=0;j--){
        suffix[j]=suffix[j+1]*arr[j+1];
    }
    for(int i=0;i<n;i++){
    product[i]=prefix[i]*suffix[i];
    }
    return product;
}




//approach 2
//t.c. o(n) s.c. o(n)
//store the prefix and suffix product in the output array itself
vector<int> productExceptSelf_2(int arr[],int n){
    vector<int> product;
    product[0]=1;
    int temp=1;
    for(int i=0;i<n;i++){
        product[i]=temp;
        temp=temp*arr[i];
    }
     temp=1;
    for(int i=n-1;i>=0;i--){
        product[i]=temp;
        temp=temp*arr[i];
    }
    return product;

}


//approach 3
//t.c. o(n) s.c. o(1)
//using log properties
//this method is not applicable if array contain 0.
int* productExceptSelf_3(int arr[],int n){
    long double log_sum=0;
    for(int i=0;i<n;i++){
        log_sum+=(long double)log10(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=(int)(pow((long double)10.00,log_sum-log10(arr[i])));
    }
    return arr;
}
//approach 4
//t.c. o(n) s.c.
//by some magic this algo works for 0
//so magic is computer can not store infitity number it has max limit
//max limit * 0 =0;
int* productExceptSelf_4(int arr[],int n){
int prod=1;
for(int i=0;i<n;i++)
 prod*=arr[i];

 for(int i=0;i<n;i++){
     arr[i]=prod*(int)pow(arr[i],-1);
 }
 return arr;
}


int main() {
    
      int arr[]={10,3,5,6,2,0,0};
      int n=sizeof(arr)/sizeof(arr[0]);
      /*int* v=productExceptSelf_3(arr,n);
      for(int i=0;i<n;i++)
       cout<<v[i]<<" ";*/

    
     return 0;
}
