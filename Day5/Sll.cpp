/*=============================================================================
#  Author:             amit meena
#  FileName:           index.cpp
#  Description:        Single Linked LIst Implementation
=============================================================================*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class SLL{

private:
    node *head, *tail;
    int size;

public:
    SLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void createSll(int value);
    void insertInSll(int value, int location);
    void traversalInSll();
    void deleteNode(int location);
    void deleteSll();
    void searchNode(int value);
};

void SLL::createSll(int value)
{
    node *tmp = new node();
    tmp->data = value;
    tmp->next = NULL;
    head = tmp;
    tail = tmp;
    size++;
}

void SLL::insertInSll(int value, int location)
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
    }
    else if (location == size+1)
    {
        tail->next = tmp;
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
        temp->next = tmp;
    }
    size++;
}

void SLL::traversalInSll()
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

void SLL::searchNode(int value)
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
void SLL::deleteNode(int location)
{
    if (head == NULL)
    return;
    else if (location == 0)
    {
        head = head->next;
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
        temp->next = temp->next->next;
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
void SLL::deleteSll()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

int main()
{
    SLL li;

    li.traversalInSll();

    li.createSll(25);
    li.insertInSll(36, 0);
    li.insertInSll(49, 0);
    li.insertInSll(64, 0);

    cout << "After adding in the first of linked list" << endl;

    li.traversalInSll();

    cout<<endl;
    
    cout<< "After adding in the end of linked list" <<endl;
    li.insertInSll(25,5);
    li.insertInSll(36,6);
    li.insertInSll(49,7);
    li.insertInSll(64,8);

    li.traversalInSll();

    cout<<endl;

    cout<<"linked list after adding 10 after node that has data =49 "<<endl;
    li.insertInSll(49,7);
    li.traversalInSll();

    li.deleteNode(5);
    li.traversalInSll();


    for(int i=0;i<3;i++){
         li.deleteNode(0);
         li.traversalInSll();
    }

    return 0;
}
