/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        max sum path in two arrays 
=============================================================================*/

#include<iostream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int max_path_sum(int A[],int B[],int l1,int l2){

int i=0,j=0;
int sum=0;
int sum1=0,sum2=0;
while(i<l1 && j <l2){
    if(A[i] < B[j]){
    sum1+=A[i];
    i++;
    }
    else if(A[i] > B[j]){
        sum2+=B[j];
        j++;
    }
    else if(A[i]==B[j]){
        sum+=max(sum1,sum2);
        sum1=0;
        sum2=0;
        while(i<l1 && j<l2 && A[i]==B[j]){
            sum+=A[i++];
            j++;
        }
    }

}
while(i>=l1 && j<l2){
    sum2+=B[j];
    j++;
}
while(j>=l2 && i<l1){
    sum1+=A[i];
    i++;
}
sum+=max(sum1,sum2);
return sum;
}
int main(){
    
    int A[]={2,3,7,10,12};
    int B[]={1,5,7,8};
    int l1=sizeof(A)/sizeof(A[0]);
    int l2=sizeof(B)/sizeof(B[0]);

    cout<<max_path_sum(A,B,l1,l2)<<endl;
    return 0;
}