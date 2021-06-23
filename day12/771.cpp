/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Jewels and Stones
=============================================================================*/
#include<iostream>
#include<unordered_set>
using namespace std;
//t.c. o(j+s) s.c. o(s);
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> hashset(jewels.begin(),jewels.end());
    int result=0;
    for(auto s:stones)
        if(hashset.count(s)) result++;
        return result;
    }
};
int main() {
    
      
    
     return 0;
}
