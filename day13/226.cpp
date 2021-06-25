/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        invert binary Tree
=============================================================================*/


//approach 1 (recursive)
TreeNode* invertTree(TreeNode* root){
    if(root){
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left,root->right);

    }
    return root;
}

//approach 2 (non recursive)

TreeNode* invertTree(TreeNode* root){
    std::stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* p=stk.top();
        stk.pop();
        if(p){
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left,p->right);
        }
    }
    return root;
}