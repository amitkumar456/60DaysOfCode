/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Circular Double Linked LIst Implementation
=============================================================================*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class CDLL{

private:
    node *head, *tail;
    int size;

public:
    CDLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void createCDLL(int value);
    void insertInCDLL(int value, int location);
    void traversalInCDLL();
    void deleteNode(int location);
    void deleteCDLL();
    void searchNode(int value);
};

void CDLL::createCDLL(int value)
{
    node *tmp = new node();
    tmp->data = value;
    tmp->next = tmp;
    tmp->prev=  tmp;
    head = tmp;
    tail = tmp;
    size++;
}

void CDLL::insertInCDLL(int value, int location)
{

    node *tmp = new node();
    tmp->data = value;
    if (head == NULL)
    {
        cout << "This is empty linked list. " << endl;
        return;
    }

    else if (location == 0)
    {
        tmp->next = head;
        head->prev=tmp;
        tail->next=tmp;
        tmp->prev=tail;
        head = tmp;
    }
    else if (location == size+1)
    {
        tail->next = tmp;
        tmp->prev=tail;
        tmp->next=head;
        tail= tmp;
        head->prev=tail;
    }
    else
    {
        node *temp = head;
        int i = 0;
        while (i < location - 1)
        {
            temp = temp->next;
            i++;
        }
        tmp->next = temp->next;
        temp->next->prev=tmp;
        tmp->prev=temp;
        temp->next = tmp;
    }
    size++;
}

void CDLL::traversalInCDLL()
{
    if (head == NULL){
        cout<<"this is empty linked list."<<endl;
        return;
    }
    node *tmp = head;
    int i=0;
    while (i<size)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
        i++;
    }
    cout<<"NULL"<<endl;
}

void CDLL::searchNode(int value)
{
    if (head == NULL)
        return;
    node *tmp = head;
    int i=0;
    while (i<size)
    {
        if (tmp->data == value)
        {
            cout << tmp->data;
            return;
        }
        i++;
    }
}
void CDLL::deleteNode(int location)
{
    if (head == NULL)
    return;
    else if (location == 0)
    {
        head=head->next;
        head->prev=tail;
        tail=head;
        if (size == 1){
        head->next=NULL;
        head->prev=NULL;
        tail=NULL;
        head=NULL;
        }
    }
    else if (location == size)
    {
        node *temp = head;
        int i=0;
        while (i<location-1)
        {   i++;
            temp = temp->next;
        }
        temp->next =head;
        tail = temp;
        if (size == 1)
        {   head->next=NULL;
            head->prev=NULL;
            tail=NULL;
            head = NULL;
        }
    }
    else
    {
        int i = 0;
        node *temp = head;
        while (i < location - 1)
        {   i++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->next->prev=temp;
    }
    size--;
}
void CDLL::deleteCDLL()
{
 
    node *temp=head;
    tail->next=NULL;
    head->prev=NULL;
    while(temp!=NULL){
        temp->prev=NULL;
        temp=temp->next;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}

int main()
{
    CDLL li;

    li.traversalInCDLL();

    li.createCDLL(25);
    li.insertInCDLL(36, 0);
    li.insertInCDLL(49, 0);
    li.insertInCDLL(64, 0);

    cout << "After adding in the first of linked list" << endl;

    li.traversalInCDLL();

    cout<<endl;
    
    cout<< "After adding in the end of linked list" <<endl;
    li.insertInCDLL(25,5);
    li.insertInCDLL(36,6);
    li.insertInCDLL(49,7);
    li.insertInCDLL(64,8);

    li.traversalInCDLL();

    cout<<endl;

    cout<<"linked list after adding 10 after node that has data =49 "<<endl;
    li.insertInCDLL(49,7);
    li.traversalInCDLL();

    li.deleteNode(5);
    li.traversalInCDLL();


    for(int i=0;i<3;i++){
         li.deleteNode(0);
         li.traversalInCDLL();
    }

    return 0;
}
