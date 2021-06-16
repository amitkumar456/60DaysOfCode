/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Subarray Sum Equals K
=============================================================================*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min(int a,int b){
    return a>b?a:b;
}
//approach 1 brute force
//t.c. o(n^2) s.c. o(1)
int subarraySum(vector<int> &nums, int k)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                result++;
        }
    }
    return result;
}



//approach 2 sliding window technique
//t.c. o(n) s.c. o(1) only works when all elements are poisitive
int subarraySum_2(vector<int>& arr, int k){

int l=0,r=0;
int result=0;
int n=arr.size();

int curr_sum=arr[0];
while(l<n && r<n){
if(curr_sum<k){
    curr_sum+=arr[++r];
}
else if(curr_sum==k){
    result++;
    curr_sum-=(arr[l++]);
}
else{
    curr_sum-=(arr[l++]);
}
}
return result;
}

//approach 3 little bit opimization in sliding window 
//t.c. o(n) s.c. o(1) works for negative number also

int subarraySum_3(vector<int> &nums,int k){
    int minEle = 1000;
    int result=0;
    int n=nums.size();
 
    for (int i = 0; i < n; i++)
        minEle = min(nums[i], minEle);
    
    for(int i=0;i<n;i++)
     nums[i]+=abs(minEle);

    return subarraySum_2(nums,k+abs(minEle));
}

//approach 4 using hashmap
//t.c. o(n) s.c. o(n) for negative number also
int subarraySum_4(vector<int> &nums,int k){
    unordered_map<int,int> m;
    int curr_sum=0;
    int n=nums.size(),result=0;
    for(int i=0;i<n;i++){
      curr_sum+=nums[i];
      if(m.find(curr_sum-k)!=m.end()){
        result++;
      }
      m[curr_sum]=i;
    }
    return result;
}
    

int main()
{

    vector<int> nums= {1};
    int k = 0;
    cout <<subarraySum_3(nums,k);

    return 0;
}
