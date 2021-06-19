/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Binary Tree Implementation by Linked List
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

class binaryTree{
public:
    node *root;
    binaryTree();
    void insertNode(int x);
    void inOrderTraversal(node* Node);
    void preOrderTraversal(node* Node);
    void postOrderTraversal(node* Node);
    void levelOrderTraversal();
    bool searchNode(int x);
    void deleteNode(int x);
    void deleteTree();
    node* getDeepestNode();
    void deleteDeepestNode();

};
binaryTree::binaryTree(){
root=NULL;
}

void binaryTree::insertNode(int x){
    node* newNode=new node(x);
    if(!root){
        root=newNode;
        return;
    }
    queue<node* > q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        if(temp->left)
         q.push(temp->left);

        else if(!temp->left){
         temp->left=newNode;
         return;
        }
        if(temp->right)
         q.push(temp->right);

        else if(!temp->right){
         temp->right=newNode;
         return;
        }
        q.pop();
    }
}

void binaryTree::preOrderTraversal(node* Node){
if(!Node)
return;

cout<<Node->data<<" ";
preOrderTraversal(Node->left);
preOrderTraversal(Node->right);
}

void binaryTree::inOrderTraversal(node* Node){
if(!Node)
return;
inOrderTraversal(Node->left);
cout<<Node->data<<" ";
inOrderTraversal(Node->right);
}

void binaryTree::postOrderTraversal(node* Node){
if(!Node)
return;
postOrderTraversal(Node->left);
postOrderTraversal(Node->right);
cout<<Node->data<<" ";
}

void binaryTree::levelOrderTraversal(){
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

bool binaryTree::searchNode(int x){
if(!root)
return false;
queue<node*> q;
q.push(root);
while(!q.empty()){
    node* temp=q.front();
    if(temp->data==x)
    return true;
    if(temp->left)
     q.push(temp->left);
    if(temp->right)
     q.push(temp->right);
    q.pop();
}
return false;
}

void binaryTree::deleteNode(int x){
    if(!root)
    return;
    queue<node* >q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        if(temp->data==x){
            temp->data=getDeepestNode()->data;
            deleteDeepestNode();
            return;
        }
        if(temp->left)
         q.push(temp->left);
        if(temp->right)
         q.push(temp->right);
        
        q.pop();
    }
}

node* binaryTree::getDeepestNode(){
    if(!root)
    return NULL;
    node* deepNode=NULL;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        if(temp->left){
         deepNode=temp->left;
         q.push(temp->left);
        }
        if(temp->right){
         deepNode=temp->right;
         q.push(temp->right);
        }
        q.pop();
    }
    return deepNode;
}

void binaryTree::deleteDeepestNode(){
    node* deepNode=getDeepestNode();
    if(!deepNode)
    return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        if(temp->left)
         q.push(temp->left);
        if(temp->left==deepNode){
            temp->left=NULL;
            return;
        }
        if(temp->right)
         q.push(temp->right);
        if(temp->right==deepNode){
            temp->right=NULL;
            return;
        }
        q.pop();
    }
}

int main() {
    
    binaryTree bt;
     cout<<"Inserting 10 nodes to tree\n";
     for(int i=0;i<10;i++){
         bt.insertNode(i*10);
     }

     cout<<"level order of tree :";
     bt.levelOrderTraversal();

     cout<<"\nPre order of tree :";
     bt.preOrderTraversal(bt.root);

     cout<<"\nin order of tree :";
     bt.inOrderTraversal(bt.root);

     cout<<"\nPost order of tree :";
     bt.postOrderTraversal(bt.root);

     cout<<"\nsearching node 50 in the tree....\n";
     cout<<((bt.searchNode(50))? "yes\n":"no\n");

     cout<<"searching node 500 in the tree....\n";
     cout<<((bt.searchNode(500))? "yes\n":"no\n");

     cout<<bt.getDeepestNode()->data;

     cout<<"deleteing deepest node\n";
     bt.deleteDeepestNode();
     bt.levelOrderTraversal();

     cout<<"\ndeleteing deepest node\n";
     bt.deleteDeepestNode();
     bt.levelOrderTraversal();

     cout<<"\ndeleteing deepest node\n";
     bt.deleteDeepestNode();
     bt.levelOrderTraversal();

     cout<<"\ndeleteing deepest node\n";
     bt.deleteDeepestNode();
     bt.levelOrderTraversal();

     
     cout<<"\ndeleting node having value 30\n";
     bt.deleteNode(30);
     bt.levelOrderTraversal();

     cout<<"\ndeleting node having value 50\n";
     bt.deleteNode(50);
     bt.levelOrderTraversal();

     cout<<"\ndeleting node having value 70\n";
     bt.deleteNode(70);
     bt.levelOrderTraversal();


    cout<<endl;
    
     return 0;
}
