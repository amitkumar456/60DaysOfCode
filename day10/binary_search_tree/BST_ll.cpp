/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Binary Search Tree Implementation using Linked List
=============================================================================*/
#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node* right;
    node* left;
    node(int x){data=x;right=NULL;left=NULL;};
};

class binarySearchTree{
public:
    node *root;
    binarySearchTree();
    void insertNode(int x);
    node* insertNode(node* Node,int x);
    void inOrderTraversal(node* Node);
    void preOrderTraversal(node* Node);
    void postOrderTraversal(node* Node);
    void levelOrderTraversal();
    bool searchNode(node* Node,int x);
    node* deleteNode(node* Node,int x);
    node* minEle(node* Node);
    void deleteTree();

};
binarySearchTree::binarySearchTree(){
root=NULL;
}

void binarySearchTree::insertNode(int x){
    root=insertNode(root,x);
}
node* binarySearchTree::insertNode(node* Node,int x){
    
    if(!Node){
    node* temp=new node(x);
    return temp;
    }
    else if(Node->data>=x)
    Node->left=insertNode(Node->left,x);
    else
    Node->right=insertNode(Node->right,x);
    return Node;
}

void binarySearchTree::preOrderTraversal(node* Node){
if(!Node)
return;

cout<<Node->data<<" ";
preOrderTraversal(Node->left);
preOrderTraversal(Node->right);
}

void binarySearchTree::inOrderTraversal(node* Node){
if(!Node)
return;
inOrderTraversal(Node->left);
cout<<Node->data<<" ";
inOrderTraversal(Node->right);
}

void binarySearchTree::postOrderTraversal(node* Node){
if(!Node)
return;
postOrderTraversal(Node->left);
postOrderTraversal(Node->right);
cout<<Node->data<<" ";
}

void binarySearchTree::levelOrderTraversal(){
    if(!root)
    return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        if(temp->left)
         q.push(temp->left);
        if(temp->right)
         q.push(temp->right);
        q.pop();
    }
}

bool binarySearchTree::searchNode(node* Node,int x){
if(!Node)
return false;
if(Node->data==x)
return true;
else if(Node->data>x)
return searchNode(Node->left,x);
else
return searchNode(Node->right,x);
}

node* binarySearchTree::minEle(node* root){
if(!root->left)
return root;
return minEle(root->left);
}

node* binarySearchTree::deleteNode(node* root,int x){
if(!root)
return NULL;
else if(root->data>x)
root->left=deleteNode(root->left,x);
else if(root->data<x)
root->right=deleteNode(root->right,x);
else{
    if(root->left && root->right){
    node* temp= minEle(root->right);
    root->data=temp->data;
    deleteNode(root->right,temp->data);
    return temp;
    }
    else if(root->left){
    root=root->left;
    }
    else if(root->right){
    root=root->right;
    }
    else{
    return NULL;
    }
}
return root;
}



int main() {
    
    binarySearchTree bst;
     cout<<"Inserting 10 nodes to tree\n";
     for(int i=0;i<10;i++){
         bst.insertNode(i*10);
     }

     cout<<"level order of tree :";
     bst.levelOrderTraversal();

     cout<<"\nPre order of tree :";
     bst.preOrderTraversal(bst.root);

     cout<<"\nin order of tree :";
     bst.inOrderTraversal(bst.root);

     cout<<"\nPost order of tree :";
     bst.postOrderTraversal(bst.root);

     cout<<"\nsearching node 50 in the tree....\n";
     cout<<((bst.searchNode(bst.root,50))? "yes\n":"no\n");

     cout<<"searching node 500 in the tree....\n";
     cout<<((bst.searchNode(bst.root,500))? "yes\n":"no\n");


     
     cout<<"\ndeleting node having value 30\n";
     bst.deleteNode(bst.root,30);
     bst.levelOrderTraversal();

     cout<<"\ndeleting node having value 50\n";
     bst.deleteNode(bst.root,50);
     bst.levelOrderTraversal();

     cout<<"\ndeleting node having value 70\n";
     bst.deleteNode(bst.root,70);
     bst.levelOrderTraversal();


    cout<<endl;
    
     return 0;
}
