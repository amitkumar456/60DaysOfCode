/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Remove Outermost Parentheses
=============================================================================*/
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
    string res;
    int opened=0;
    for(char c:s){
        if(c=='(' && opened++>0) res+=c;
        if(c==')' && opened-->1) res+=c;
    }
    return res;
    }
};
int main() {
    
      
    
     return 0;
}
