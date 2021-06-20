/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        AVL Tree Implementation using Linked List
=============================================================================*/
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct node{
    int   data;
    int   height;
    node* right;
    node* left;
    node(int x){data=x; right=NULL; left=NULL; height=0;};
};

class avlTree{
public:
    node *root;
    avlTree();
    void  insertNode(int x);
    node* insertNode(node* Node,int x);
    void  inOrderTraversal(node* Node);
    void  preOrderTraversal(node* Node);
    void  postOrderTraversal(node* Node);
    void  levelOrderTraversal();
    bool  searchNode(node* Node,int x);
    node* deleteNode(node* Node,int x);
    node* minEle(node* Node);
    void  deleteTree();
    node* leftRotation(node* Node);
    node* rightRotation(node* Node);
    int   calculateHeight(node* Node);
    int   checkBalance(node* Node);

};

avlTree::avlTree(){
root=NULL;
}

void avlTree::insertNode(int x){
    root=insertNode(root,x);
}
node* avlTree::insertNode(node* Node,int x){
    
    if(!Node){
    node* temp=new node(x);
    return temp;
    }
    else if(Node->data>=x)
    Node->left=insertNode(Node->left,x);
    else
    Node->right=insertNode(Node->right,x);
    int balance=checkBalance(Node);
    if(balance>1){
    if(calculateHeight(Node->left->left)-calculateHeight(Node->left->right)>0){
    Node=rightRotation(Node);
    }
    else{
    Node->left=leftRotation(Node->left);
    Node=rightRotation(Node);
    }
    }
    else if(balance<-1){
    if(calculateHeight(Node->right->right)-calculateHeight(Node->right->left)>0){
    Node=leftRotation(Node);
    }
    else{
    Node->right=rightRotation(Node->right);
    Node=leftRotation(Node);
    }
    }
    return Node;
}

void avlTree::preOrderTraversal(node* Node){
if(!Node)
return;

cout<<Node->data<<" ";
preOrderTraversal(Node->left);
preOrderTraversal(Node->right);
}

void avlTree::inOrderTraversal(node* Node){
if(!Node)
return;
inOrderTraversal(Node->left);
cout<<Node->data<<" ";
inOrderTraversal(Node->right);
}

void avlTree::postOrderTraversal(node* Node){
if(!Node)
return;
postOrderTraversal(Node->left);
postOrderTraversal(Node->right);
cout<<Node->data<<" ";
}

void avlTree::levelOrderTraversal(){
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

bool avlTree::searchNode(node* Node,int x){
if(!Node)
return false;
if(Node->data==x)
return true;
else if(Node->data>x)
return searchNode(Node->left,x);
else
return searchNode(Node->right,x);
}

node* avlTree::minEle(node* root){
if(!root->left)
return root;
return minEle(root->left);
}

node* avlTree::deleteNode(node* Node,int x){
if(!Node)
return NULL;
else if(Node->data>x)
Node->left=deleteNode(Node->left,x);
else if(Node->data<x)
Node->right=deleteNode(Node->right,x);
else{
    if(Node->left && Node->right){
    node* temp= minEle(Node->right);
    Node->data=temp->data;
    deleteNode(Node->right,temp->data);
    return Node;
    }
    else if(Node->left){
    Node=Node->left;
    }
    else if(Node->right){
    Node=Node->right;
    }
    else{
    return NULL;
    }
}
int balance=checkBalance(Node);
if(balance>1){
    if(calculateHeight(Node->left->left)-calculateHeight(Node->left->right)>0){
    Node=rightRotation(Node);
    }
    else{
    Node->left=leftRotation(Node->left);
    Node=rightRotation(Node);
    }
    }
    else if(balance<-1){
    if(calculateHeight(Node->right->right)-calculateHeight(Node->right->left)>0){
    Node=leftRotation(Node);
    }
    else{
    Node->right=rightRotation(Node->right);
    Node=leftRotation(Node);
    }
}
return Node;
}


int avlTree::calculateHeight(node* Node){
if(!Node)
return -1;

return max(calculateHeight(Node->left),calculateHeight(Node->right))+1;
}
node* avlTree::rightRotation(node* currentDisbalancedNode){
node* newroot=currentDisbalancedNode->left;
currentDisbalancedNode->left=newroot->right;
newroot->right=currentDisbalancedNode;
newroot->height=calculateHeight(newroot);
currentDisbalancedNode->height=calculateHeight(currentDisbalancedNode);

return newroot;
}

node* avlTree::leftRotation(node* currentDisbalancedNode){
node* newroot=currentDisbalancedNode->right;
currentDisbalancedNode->right=newroot->left;
newroot->left=currentDisbalancedNode;
newroot->height=calculateHeight(newroot);
currentDisbalancedNode->height=calculateHeight(currentDisbalancedNode);
return newroot;
} 

int avlTree::checkBalance(node* Node){
    if(!Node->left && !Node->right)
    return 0;
    else if(!Node->left && Node->right)
    return -(1+calculateHeight(Node->right));
    else if(!Node->right && Node->left)
    return calculateHeight(Node->left)+1;
    else
    return calculateHeight(Node->left)-calculateHeight(Node->right);
}



int main() {
    
     avlTree avl;
     cout<<"Inserting 10 nodes to tree\n";
     for(int i=0;i<10;i++){
         avl.insertNode(i*10);
     }

     cout<<"level order of tree :";
     avl.levelOrderTraversal();

     cout<<"\nPre order of tree :";
     avl.preOrderTraversal(avl.root);

     cout<<"\nin order of tree :";
     avl.inOrderTraversal(avl.root);

     cout<<"\nPost order of tree :";
     avl.postOrderTraversal(avl.root);

     cout<<"\nsearching node 50 in the tree....\n";
     cout<<((avl.searchNode(avl.root,50))? "yes\n":"no\n");

     cout<<"searching node 500 in the tree....\n";
     cout<<((avl.searchNode(avl.root,500))? "yes\n":"no\n");


     
     cout<<"\ndeleting node having value 30\n";
     avl.deleteNode(avl.root,30);
     avl.levelOrderTraversal();

     cout<<"\ndeleting node having value 50\n";
     avl.deleteNode(avl.root,50);
     avl.levelOrderTraversal();

     cout<<"\ndeleting node having value 70\n";
     avl.deleteNode(avl.root,70);
     avl.levelOrderTraversal();


    cout<<endl;
    
     return 0;
}
