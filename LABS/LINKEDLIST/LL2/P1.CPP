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

Node *top = NULL;

void push(int data)
{
    Node *node1 = new Node(data);
    node1->next = top;
    top = node1;
}

int pop()
{
    if (top == NULL)
    {
        cout << "Stack underflow";
        return -1;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        int ans = temp->data;
        delete temp;
        return ans;
    }
}

int main()
{
    push(10);
    push(12);
    push(20);
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    return 0;
}
