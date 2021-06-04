/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Sorted_subsequence_of_size3
=============================================================================*/
#include<iostream>
#include<climits>
using namespace std;


//approach 1 brute force t.c. o(n^3) s.c. o(1)
int find3Numbers_1(int A[],int n){
int result=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(A[i]>A[j])
        break;
        for(int k=j+1;k<n;k++){
            if(A[i]<A[j] && A[j]<A[k])
            result++;
        }
    }
}
return result;
}

//approach 2 
//if we choose any number then index before that number has small element and index after that element must have greater element.
//t.c. o(n^2) s.c. o(1)
int find3Numbers_2(int A[],int n){
int result=0;
for(int i=0;i<n;i++){
    int smaller=A[i];
    int larger =A[i];
    for(int j=0;j<i;j++){
    if(smaller<A[j])
    smaller=A[j];
    }
    for(int k=i+1;k<n;k++){
    if(larger>A[k])
    larger=A[k];
    }
    if(smaller!=A[i] && larger!=A[i])
    result++;
}
return result;
}
//approach 3
//t.c. o(N) and s.c. o(n)
int find3Numbers_3(int A[],int n){
   int min=0;
   int max=n-1;
   int* smaller=new int[n];
   smaller[0]=-1;
   int i;
   for(i=1;i<n;i++){
   if(A[i]<=A[min]){
       min=i;
       smaller[i]=-1;
   }
   else
   smaller[i]=min;
   }
   int* greater=new int[n];
   greater[n-1]=-1;
   for(i=n-2;i>=0;i--){
   if(A[i]>=A[max]){
   max=i;
   greater[i]=-1;
   }
   else
   greater[i]=max;
   }
   for(int i=0;i<n;i++){
   if(smaller[i]!=-1 && greater[i]!=-1)
   cout<<A[smaller[i]]<<" "<<A[i]<<A[greater[i]]<<endl;
   return 1;
   }
   cout<<"no such triplet found";
   delete[] smaller;
   delete[] greater;
   return -1;
}

//approach 4
//t.c. o(n) s.c. o(n)
int find3Numbers_4(int A[], int n){
    if(n<3){
        cout<<"no such triplet found";
        return;
    }
    int seq=1;

    int min_num=A[0];

    int max_seq=INT_MIN;

    int store_min=min_num;

    for(int i=1;i<n;i++){
        if(A[i]==min_num)
        continue;

        else if(A[i]<min_num){
            min_num=A[i];
            continue;
        }

        else if(A[i]<max_seq){
            max_seq=A[i];
            store_min=min_num;
        }
        else if(A[i]>max_seq){
            seq++;
            if(seq==3){
                cout<<"Triplet: "<<store_min<<", "<<max_seq<<", "<<A[i]<<endl;
                return;
            }
            max_seq=A[i];
        }
    }
    cout<<" NO such Triplet found";
    return ;
}
int main() {
    
     int A[]={1,2,1,1,3};
     int n  =sizeof(A)/sizeof(A[0]);
     cout<<find3Numbers_1(A,n)<<endl;
    
     return 0;
}
