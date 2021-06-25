/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        maximum depth of binary tree
=============================================================================*/
#include<iostream>
using namespace std;

//dfs solution
int maxDepth(TreeNode* root){
    return root==NULL? 0 : max(maxDepth(root->left),maxDepth(root->right))+1;

}

//bfs solution
//calculate the count of the last level

int maxDepth(TreeNode* root){
    if(root==NULL)
    return 0;

    int res=0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        res++;
        for(int i=0;n=q.size();i<n;i++){
            TreeNode* p=q.front();
            q.pop();
            if(q->left!=NULL)
             q.push(p->left);
            if(q->right!=NULL)
             q.push(p->right);
        }
    }
    return res;
}
int main() {
    
      
    
     return 0;
}
