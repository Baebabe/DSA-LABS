#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    
    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int data)
    {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(16);
    q.enqueue(18);

    cout << "Dequeued elements are:" << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << "Is the queue empty? " << (q.isEmpty() ? "TRUE" : "FALSE") << endl;

    return 0;
}
