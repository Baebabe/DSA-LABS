#include <iostream>
using namespace std;
class Queue
{
public:
    struct Node
    {
        int value;
        int next;
    };

    Node *nodes;
    int avail, head, tail;

    Queue(int capacity)
    {
        nodes = new Node[capacity];
        avail = 0;
        head = tail = -1;

        for (int i = 0; i < capacity - 1; ++i)
        {
            nodes[i].next = i + 1;
        }
        nodes[capacity - 1].next = -1;
    }

    bool empty()
    {
        return head == -1;
    }

    void enqueue(int value)
    {
        if (avail == -1)
        {
            return;
        }

        int new_node = avail;
        avail = nodes[avail].next;

        nodes[new_node].value = value;
        nodes[new_node].next = -1;

        if (tail == -1)
        {
            head = tail = new_node;
        }
        else
        {
            nodes[tail].next = new_node;
            tail = new_node;
        }
    }

    int dequeue()
    {
        if (head == -1)
        {
            return -1;
        }

        int value = nodes[head].value;
        int to_del = head;
        head = nodes[head].next;

        nodes[to_del].next = avail;
        avail = to_del;

        if (head == -1)
        {
            tail = -1;
        }

        return value;
    }
};

int main()
{
    Queue q(3);

    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(5);

    cout << q.dequeue() << ' ';
    cout << q.dequeue() << ' ';
    cout << q.dequeue() << ' ';

    cout << '\n';

    return 0;
}
