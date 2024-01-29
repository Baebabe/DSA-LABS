#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
    }
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data)
{
    Node *node1 = new Node(data);
    if (front == NULL)
    {
        front = rear = node1;
    }
    else
    {
        rear->next = node1;
        rear = node1;
    }
}
int dequeue()
{
    if (front == NULL)
    {
        return -1;
    }
    int elem = -1;
    Node *temp = front;
    front = front->next;
    elem = temp->data;
    delete temp;

    if (front == NULL)
    {
        rear = NULL;
    }

    return elem;
}

int main()
{
    enqueue(12);
    enqueue(15);
    enqueue(14);
    enqueue(16);
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    return 0;
}
