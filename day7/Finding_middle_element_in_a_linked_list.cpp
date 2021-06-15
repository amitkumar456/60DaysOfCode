/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Finding middle element in a linked list
=============================================================================*/
#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x){
        val=x;
        next=NULL;
    }
};
//approach 1 first calculating the size of linked list then traversing half
//t.c. o(N) s.c. o(1)
int getMiddle_1(node *head){
node* temp=head;
int size=0;
while(temp){
    size++;
    temp=temp->next;
}
temp=head;
size=size/2;
while(size--){
    temp=temp->next;
}
return temp->val;
}
//approach 2 
//using fast and slower pointer
int getMiddle_2(node *head){
    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
int main() {
    
      
    
     return 0;
}
