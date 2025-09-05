#include <iostream>
using namespace std;

// Node class
class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
private:
    node *head = NULL;

public:
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

    void insert_at_beg(int value)
    {
        node *temp = new node();
        temp->data = value;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insert_at_end(int value)
    {
        node *temp = new node();
        temp->data = value;
        node *t = head;
        if (head == NULL)
        {
            temp = head;
        }
        else
        {
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            temp->prev = t;
        }
    }

    void insert_at_middle(int pos, int value)
    {
        node *temp = new node();
        temp->data = value;
        if (pos == 1)
        {
            temp->next = head;
            head->prev = temp;
        }
        else
        {
            node *t = head;
            while ((pos - 2 != 0) && (t->next != NULL))
            {
                t = t->next;
                pos--;
            }

            // we need to maintain four pointers in doubly LL
            temp->next = t->next;
            temp->prev = t;
            t->next->prev = temp;
            t->next = temp;
        }
    }

    void delete_at_beg()
    {
        if (head == NULL)
        {
            cout << "Deletion not possible, DLL is empty" << endl;
        }
        else if (head->next == NULL)
        {
            delete (head);
            head = NULL;
        }
        else
        {
            node *t = head;
            t = t->next;
            t->prev = NULL;
            delete (head);
            head = t;
        }
    }

    void delete_at_end()

    {
        if (head == NULL)
        {
            cout << "DLL is empty" << endl;
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
            node *last = t->next;
            t->next = NULL;
            delete (last);
        }
    }

    void delete_at_pos(int pos)
    {
        }
};