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
    // pointer is of the type to the type which it points to it
    void insert_at_end(int val)
    {
        node *temp = new node();
        temp->data = val;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }

    // insert in the middle
    void insert_in_middle(int val, int pos)
    {
        node *temp = new node();
        temp->data = val;

        if (pos == 1)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            node *t = head;
            while (((pos - 2) != 0) && (t->next != NULL))
            {
                t = t->next;
                pos--;
            }
            temp->next = t->next;
            t->next = temp;
        }
    }

    void delete_at_beginning()
    {
        if (head == NULL)
        {
            cout << "Deletion not possible" << endl;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete (temp);
        }
    }

    void delete_at_end()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
        }
        else if (head->next == NULL)
        {
            delete (head);
            head = NULL;
        }
        else
        {
            node *t = head;
            while (t->next->next != NULL)
            {
                t = t->next;
            }
            delete (t->next);
            t->next = NULL;
        }
    }
    void delete_at_pos(int pos)
    {
        if (head == NULL)
        {
            cout << "Not Possible" << endl;
        }
        else if (pos == 1)
        {
            node *t = head;
            head = head->next;
            delete (t);
        }
        else
        {
            node *t = head;
            while (((pos - 2) != 0) && (t->next != NULL))
            {
                t = t->next;
                pos--;
            }
            node *temp = t->next;
            t->next = temp->next;
            delete (temp);
        }
    }
};

int main()
{
    LinkedList ll;
    ll.insert_at_beg(10);
    ll.insert_at_beg(20);
    ll.insert_at_beg(30);
    ll.insert_at_beg(40);
    ll.insert_at_end(50);
    ll.insert_in_middle(100, 4);
    cout << "After Insertion" << endl;
    ll.print();
    cout << endl;
    ll.delete_at_beginning();
    cout << "After deleting from beginning" << endl;
    ll.print();
    cout << endl;
    ll.delete_at_end();
    cout << "After deleting from end" << endl;
    ll.print();
    cout << endl;
    ll.delete_at_pos(3);
    cout << "After deleting from position 3" << endl;
    ll.print();
    return 0;
}