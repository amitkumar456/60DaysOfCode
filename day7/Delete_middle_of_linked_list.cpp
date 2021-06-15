/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Delete Middle of linked list
=============================================================================*/


#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
//appraoch 1
//first counting the size of the ll then traversing one element before mid
//t.c. o(N) s.c.o(1)

Node* deleteMid(Node* head){
        if(!head)
    return NULL;
    int size=0;
    Node* temp=head;
    while(temp){
        size++;
        temp=temp->next;
    }
    temp=head;
    if(size==1)
    return NULL;
    size=(size/2)-1;
    while(size--){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}

int main() {
    
      
    
     return 0;
}
