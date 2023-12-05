#include <iostream>
#include <climits>
using namespace std;

class stack
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stack()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    stack s;
    cout << "10 is pushed in stack" << endl;
    s.push(10);
    cout << "20 is pushed in stack" << endl;
    s.push(20);
    cout << "30 is pushed in stack" << endl;
    s.push(30);
    cout << "40 is pushed in stack" << endl;
    s.push(40);
    cout << "50 is pushed in stack" << endl;
    s.push(50);
    cout << "Top of stack = " << s.top() << endl;
    cout << s.pop() << " is poped from stack" << endl;
    cout << s.pop() << " is poped from stack" << endl;
    cout << s.pop() << " is poped from stack" << endl;
    cout << "Size of stack = " << s.size() << endl;
    cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
    return 0;
}