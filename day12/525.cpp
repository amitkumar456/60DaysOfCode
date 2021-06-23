/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Contiguous Array
=============================================================================*/
#include<iostream>
using namespace std;

//bruteforce solution t.c. o(n^2) s.c. o(1) TLE
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    int n=nums.size();
    int one,zero,result=0;
    for(int i=0;i<n;i++){
        one=0,zero=0;
        int temp=0;
        for(int j=i;j<n;j++){
            if(nums[j]==1)
                one++;
            else
                zero++;
            if(one==zero)
                temp=2*one;
        }
        if(temp>=result)
            result=temp;
    }
        return result;
    }
};
int main() {
    
      
    
     return 0;
}
