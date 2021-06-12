/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Merge Two Sorted Lists [21]
=============================================================================*/
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0),next(NULL) {};
    ListNode(int x): val(x), next(NULL) {};
}

class Solution{
    public:
     ListNode* mergeTwoLists(ListNode* l1,ListNOde* l2){
         ListNode *head=new ListNode(0);
         ListNode *temp=head;

         while(l1 && l2){
             if(l1->val > l2->val){
                 temp->next=l2;
                 l2=l2->next;
             }
             else{
                 temp->next=l1;
                 l1=l1->next;
             }
             temp=temp->next;
         }

         temp->next = l1? l1:l2;
         head=head->next;
         return head;
     }
}
int main() {
    
      
    
     return 0;
}
