/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Circular Single Linked LIst Implementation
=============================================================================*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class CSLL{

private:
    node *head, *tail;
    int size;

public:
    CSLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void createCsll(int value);
    void insertInCsll(int value, int location);
    void traversalInCsll();
    void deleteNode(int location);
    void deleteCsll();
    void searchNode(int value);
};

void CSLL::createCsll(int value)
{
    node *tmp = new node();
    tmp->data = value;
    tmp->next = NULL;
    head = tmp;
    tail = tmp;
    tmp->next=head;
    size++;
}

void CSLL::insertInCsll(int value, int location)
{

    node *tmp = new node();
    tmp->data = value;
    tmp->next = NULL;
    if (head == NULL)
    {
        cout << "This is empty linked list. " << endl;
        return;
    }

    else if (location == 0)
    {
        tmp->next = head;
        head = tmp;
        tail->next=tmp;
    }
    else if (location == size+1)
    {
        tail->next = tmp;
        tail = tmp;
        tmp->next=head;
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
        temp->next = tmp;
    }
    size++;
}

void CSLL::traversalInCsll()
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

void CSLL::searchNode(int value)
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
        tmp=tmp->next;
        i++;
    }
}
void CSLL::deleteNode(int location)
{
    if (head == NULL)
    return;
    else if (location == 0)
    {
        head = head->next;
        tail->next=head;
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
        temp->next = head;
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
    }
    size--;
}
void CSLL::deleteCsll()
{
    tail->next=NULL;
    head = NULL;
    tail = NULL;
    size = 0;
}

int main()
{
    CSLL li;

    li.traversalInCsll();

    li.createCsll(25);
    li.insertInCsll(36, 0);
    li.insertInCsll(49, 0);
    li.insertInCsll(64, 0);

    cout << "After adding in the first of linked list" << endl;

    li.traversalInCsll();

    cout<<endl;
    
    cout<< "After adding in the end of linked list" <<endl;
    li.insertInCsll(25,5);
    li.insertInCsll(36,6);
    li.insertInCsll(49,7);
    li.insertInCsll(64,8);

    li.traversalInCsll();

    cout<<endl;

    cout<<"linked list after adding 10 after node that has data =49 "<<endl;
    li.insertInCsll(49,7);
    li.traversalInCsll();

    li.deleteNode(5);
    li.traversalInCsll();


    for(int i=0;i<3;i++){
         li.deleteNode(0);
         li.traversalInCsll();
    }

    return 0;
}
