/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Reverse a Linked List
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
 //approach 1 
 //creating a new linked list of given linked list
 //t.c. o(n) s.c. o(n)
 struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
         if(!head)
         return NULL;
         if(!head->next)
         return head;
         Node* new_head=new Node(head->data);
         Node* temp=head->next;;
         while(temp){
            Node *curr=new Node(temp->data);
            curr->next=new_head;
            new_head=curr;
            temp=temp->next;
         }
         return new_head;
    }
//approach 2 constant space
//t.c. o(n) s.c. o(1)
 struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(!head)
         return NULL;
        if(!head->next)
         return head;
         
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        }
        return prev;
    }

 //recursive algo
 //t.c. o(n) s.c. o(1)
 struct Node* reverseList_3(struct Node *head){
     if(!head && !head->next)
     return NULL;

     Node* rest=reverseList_3(head->next);
     head->next->next=head;
     head->next=NULL;

     return rest;
 }

int main() {
    
      
    
     return 0;
}
