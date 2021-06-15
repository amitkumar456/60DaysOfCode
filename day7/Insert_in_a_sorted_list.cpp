/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Insert in a sorted list
=============================================================================*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* node=new Node(data);
        Node* curr=head;
        Node* prev=NULL;
        while(curr && (curr->data < data)){
            prev=curr;
            curr=curr->next;
        }
        if(!prev){
            node->next=head;
            head=node;
        }
        else{
            node->next=prev->next;
            prev->next=node;
        }
        
        return head;
    }
int main() {
    
      
    
     return 0;
}
