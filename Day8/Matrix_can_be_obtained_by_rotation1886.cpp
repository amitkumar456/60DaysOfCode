/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Determine Whether Matrix Can Be Obtained By Rotation
=============================================================================*/
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
//approach 1
//first we calculate all four permutation of rotatio matrix and then we will compare it with target matrix

bool findRotation(vector<vector<int>> &mat, vector< vector<int>> &target){

    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> temp(n,vector<int>(m,0));
    for(int k=1;k<5;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            temp[n-i-j][i]=mat[i][j];
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]!=target[i][j]){
                    flag=false;
                    break;
                }
            }
            if(!flag)
             break;
        }
        if(flag)
         return true;
        mat=temp;
    }
    return false;
}



//arpproach 2
//using rotation propertyies
//t.c. o(n) s.c. o(1)

bool findRotation_2(vector<vector<int>> &mat, vector<vector<int>> &target)
{

bool c[4];
memset(c,true,sizeof(c));
int n=mat.size();
int m=mat[0].size();

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]!=target[i][j]) c[0]=false;
        if(mat[i][j]!=target[n-1-j][i]) c[1]=false;
        if(mat[i][j]!=target[n-1-i][n-1-j]) c[2]=false;
        if(mat[i][j]!=target[j][n-i-1]) c[3]=false;
    }
}
return c[0]||c[1]||c[2]||c[3];
}

int main(){

    vector<vector<int>> mat = {{0,1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    
   (findRotation_2(mat,target))? cout<<"yes":cout<<"no";

    return 0;
}
