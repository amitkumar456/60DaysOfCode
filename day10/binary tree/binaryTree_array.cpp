/*=============================================================================
#  Author:             amit meena
#  FileName:           test.cpp
#  Description:        Binary Tree Implementation by Array
=============================================================================*/
#include<iostream>
#include<queue>
using namespace std;


class binaryTree{
    int *arr;
    int size;
    int lastIndex;
public:
    binaryTree(int capacity);
    void insertNode(int x);
    void inOrderTraversal(int i);
    void preOrderTraversal(int i);
    void postOrderTraversal(int i);
    void levelOrderTraversal();
    bool searchNode(int x);
    void deleteNode(int x);
    void deleteTree();
};
binaryTree::binaryTree(int capacity){
lastIndex=0;
size=capacity;
arr=new int[size+1];
}

void binaryTree::insertNode(int x){
if(!arr)
return;
if(lastIndex==size)
return;
arr[++lastIndex]=x;
return;
}

void binaryTree::preOrderTraversal(int i){
if(i>size)
return;

cout<<arr[i]<<" ";
preOrderTraversal(2*i);
preOrderTraversal(2*i+1);
}

void binaryTree::inOrderTraversal(int i){
if(i>size)
return;

inOrderTraversal(2*i);
cout<<arr[i]<<" ";
inOrderTraversal(2*i+1);
}

void binaryTree::postOrderTraversal(int i){
if(i>size)
return;

postOrderTraversal(2*i);
postOrderTraversal(2*i+1);
cout<<arr[i]<<" ";
}

void binaryTree::levelOrderTraversal(){
if(!arr)
return;
for(int i=1;i<=lastIndex;i++){
    cout<<arr[i]<<" ";
}
}

bool binaryTree::searchNode(int x){
if(!arr)
return false;
for(int i=0;i<=lastIndex;i++){
if(arr[i]==x)
return true;
}
return false;
}

void binaryTree::deleteNode(int x){
if(!arr)
return;
for(int i=1;i<=lastIndex;i++){
    if(arr[i]==x){
        arr[i]=arr[lastIndex--];
        return;
    }
}
}

void binaryTree::deleteTree(){
    arr=NULL;
}



int main() {
    
    binaryTree bt(10);
     cout<<"Inserting 10 nodes to tree\n";
     for(int i=1;i<11;i++){
         bt.insertNode(i*10);
     }

     cout<<"level order of tree :";
     bt.levelOrderTraversal();

     cout<<"\nPre order of tree :";
     bt.preOrderTraversal(1);

     cout<<"\nin order of tree :";
     bt.inOrderTraversal(1);

     cout<<"\nPost order of tree :";
     bt.postOrderTraversal(1);

     cout<<"\nsearching node 50 in the tree....\n";
     cout<<((bt.searchNode(50))? "yes\n":"no\n");

     cout<<"searching node 500 in the tree....\n";
     cout<<((bt.searchNode(500))? "yes\n":"no\n");

     
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
