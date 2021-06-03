/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Remove duplicates in samll prime array
=============================================================================*/
#include<iostream>
#include<vector>
using namespace std;

//brute force t.c. o(n^2) && s.c. o(n)
vector<int> removeDuplicate_1(int arr[], int n){
    vector<int> v;
    for(int i=0;i<n;i++){
        int j=0;
        for(j;j<i;j++){
            if(arr[j]==arr[i])
            break;
        }
        if(j==i)
        v.push_back(v[i]);
        
    }
    return v;
}

//little bit optimization using same array t.c. o(n^2) s.c. o(1)
vector<int> removeDuplicate_2(vector<int> &v, int n){
    int res_ind=1;
    for(int i=0;i<n;i++){
        int j=0;
        for(j;j<i;j++){
            if(arr[j]==arr[i])
            break;
        }
        if(j==i)
        v[res_ind++]=v[i];
        
    }
    v.erase(v.begin()+res_ind,v.end());
    return v;
}

#little bit more optimization by sorting t.c. nlogn
vector<int> removeDuplicate_3(vector<int>& vect){
sort(vect.begin(),vect.end());
vect.erase(unique(vect.begin(),vect.end()),vect.end());
return vect;


}
//approach using hashset 

vector<int> removeDuplicate_5(vector<int> &v){

    unordered_set<int> s(v.begin(),v.end());
    v.assign(s.begin(),s.end());
    return v;
}

//approach 5 using another array for storing frequency of elements.
vector<int> removeDuplicate_5(int arr[], int n){
vector<int> v;
int res_ind=0;
vector<int> hash(100,0);
for(int i=0;i<n;i++){
    hash[arr[i]]++;
    if(hash[arr[i]]==1)
    arr[res_ind++]=arr[i];
}
return v;
}

// approach 6 using property of prime(i.e. divisor is 1 or itself) 
vector<int> removeDuplicate_6(vector<int> &v){
    long long prod=vect[0];
    int res_ind=1;
    for(int i=1;i<vect.size();i++){
        if(prod%vect[i]!=0)
        vect[res_ind++]=vect[i];
        prod*=vect[i];
    }
    v.erase(v.begin()+res_ind,v.end());
    return v;
}
int main() {
    
     int a[]={2,2,3,3,7,5};
     int n  =sizeof(a)/sizeof(a[0]);
     vector<int> v=removeDuplicate(a,n);
     for(auto a:v)
     cout<<a<<" ";
     return 0;
}

