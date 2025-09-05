#include <iostream>
using namespace std;

class queue
{
private:
    static const int N = 100;
    int q[N];
    int front;
    int rear;

public:
    queue()
    {
        front = rear = -1;
    }

    void enqueue(int x)
    {
        if (rear == N - 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
                q[front] = x;
            }
            else
            {
                rear++;
                q[rear] = x;
            }
        }
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front++;
            }
        }
    }

    void print()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << endl;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(50);
    q.print();
    return 0;
}