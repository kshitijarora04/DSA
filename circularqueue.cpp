#include <iostream>
using namespace std;

class CircularQueue
{
private:
    static const int N = 5; // fixed size
    int q[N];
    int front;
    int rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % N == front);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % N;
        }
        q[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) // only one element
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.dequeue();
    cq.enqueue(60);
    cq.print();
    return 0;
}
