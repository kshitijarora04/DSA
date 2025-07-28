#include <iostream>
using namespace std;

// Node class
class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

// Linked List class
class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // print a linked list
    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty";
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }

    // insert at the beginning a of linked list
    void insert_at_beg(int val)
    {
        node *temp = new node();
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    // insert at the end of the linked list
    void insert_at_end(int val)
    {
    }

    // insert in the middle
    void insert_in_middle(int pos, int val)
    {
    }
};

int main()
{
    LinkedList ll;
    ll.insert_at_beg(10);
    ll.insert_at_beg(20);
    ll.insert_at_beg(30);
    ll.insert_at_beg(40);
    ll.print();
    return 0;
}