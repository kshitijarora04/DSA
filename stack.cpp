#include <iostream>
using namespace std;

class Stack
{
private:
    static const int N = 100;
    int arr[N];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == N - 1)
        {
            cout << "Stack Overflow, Insertion Not Possible" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    cout << "Before Popping" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Peeking element: " << s.peek() << endl;
    s.print();
    cout << "After Popping" << endl;
    s.pop();
    s.print();
    return 0;
}