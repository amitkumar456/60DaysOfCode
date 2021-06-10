/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Double Linked LIst Implementation
=============================================================================*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class DLL{

private:
    node *head, *tail;
    int size;

public:
    DLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void createDLL(int value);
    void insertInDLL(int value, int location);
    void traversalInDLL();
    void deleteNode(int location);
    void deleteDLL();
    void searchNode(int value);
};

void DLL::createDLL(int value)
{
    node *tmp = new node();
    tmp->data = value;
    tmp->next = NULL;
    tmp->prev=  NULL;
    head = tmp;
    tail = tmp;
    size++;
}

void DLL::insertInDLL(int value, int location)
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
        tmp->prev=NULL;
        head = tmp;
    }
    else if (location == size+1)
    {
        tail->next = tmp;
        tmp->prev=tail;
        tmp->next=NULL;
        tail = tmp;
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

void DLL::traversalInDLL()
{
    if (head == NULL){
        cout<<"this is empty linked list."<<endl;
        return;
    }
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout<<"NULL"<<endl;
}

void DLL::searchNode(int value)
{
    if (head == NULL)
        return;
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == value)
        {
            cout << tmp->data;
            return;
        }
    }
}
void DLL::deleteNode(int location)
{
    if (head == NULL)
    return;
    else if (location == 0)
    {
        head = head->next;
        head->prev=NULL;
        if (size == 1)
            tail = NULL;
    }
    else if (location == size)
    {
        node *temp = head;
        int i=0;
        while (i<location-1)
        {   i++;
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        if (size == 1)
        {
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
void DLL::deleteDLL()
{
 
    node *temp=head;
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
    DLL li;

    li.traversalInDLL();

    li.createDLL(25);
    li.insertInDLL(36, 0);
    li.insertInDLL(49, 0);
    li.insertInDLL(64, 0);

    cout << "After adding in the first of linked list" << endl;

    li.traversalInDLL();

    cout<<endl;
    
    cout<< "After adding in the end of linked list" <<endl;
    li.insertInDLL(25,5);
    li.insertInDLL(36,6);
    li.insertInDLL(49,7);
    li.insertInDLL(64,8);

    li.traversalInDLL();

    cout<<endl;

    cout<<"linked list after adding 10 after node that has data =49 "<<endl;
    li.insertInDLL(49,7);
    li.traversalInDLL();

    li.deleteNode(5);
    li.traversalInDLL();


    for(int i=0;i<3;i++){
         li.deleteNode(0);
         li.traversalInDLL();
    }

    return 0;
}
