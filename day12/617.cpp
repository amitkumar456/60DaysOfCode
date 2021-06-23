/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Merge two binary tree
=============================================================================*/
#include<iostream>
using namespace std;





  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    //idea is same as inserting a value in binary tree
    //t.c. o(n) s.c. o(logn) in worst skewed case it can go to o(n)
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return NULL;
        if(!root1 && root2)
            return root2;
        if(!root2 && root1)
            return root1;
        if(root1 && root2)
            root1->val+=root2->val;
        
        
        root1->left= mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};

int main(){

    return 0;
}