#include<iostream>
using namespace std;

void rotation(int A[],int n){
    int temp=A[0];
    for(int i=0;i<n-1;i++)
    A[i]=A[i+1];
    A[n-1]=temp;
}

//approach 1 brute force t.c. o(n^2) s.c. o(1)
int max_sum(int A[],int n){
    int sum_global=0;
    for(int i=0;i<n;i++){
        rotation(A,n);
        int sum=0;
        for(int j=0;j<n;j++)
        sum+=j*A[j];
        if(sum>sum_global)
        sum_global=sum;
    }
    return sum_global;
}

//approach 2 t.c. o(n) s.c. o(1)
//calculating the next rotation sum using presious calculated sum
int max_sum_2(int A[], int n){
int cum_sum=0;
int curr_val=0;
for(int i=0;i<n;i++){
    cum_sum+=A[i];
    curr_val+=A[i]*i;
}

int result=0;
for(int i=1;i<n;i++){
    int next_val=curr_val-(cum_sum-A[i-1])+(n-1)*A[i-1];
    curr_val=next_val;
    if(next_val>result)
    result=next_val;
}
return result;
}


//approach 3 if sorted array or sorted rotated array is given then max sum occur when array in ascending order
int max_sum_3(int A[],int n){
    int pivot=0;
    int result=0;
    for(int i=0;i<n;i++){
        if(A[i]>A[(i+1)%n])
        pivot=(i+1)%n;
    }
    int diff=n-1-pivot;
    for(int i=0;i<n;i++){
        result+=A[i]*(i+diff)%n;
    }
    return result;
}


int main() {
    
    int A[]={4,5,1,2};
    int n=sizeof(A)/sizeof(A[0]);
    
    cout<<max_sum_3(A,n)<<endl;
    
     return 0;
}
