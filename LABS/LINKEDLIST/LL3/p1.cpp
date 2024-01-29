//circular linked list
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
        delete next;
    }
};
void insertNode(Node *&tail, int value, int data)
{

    if (tail == NULL)
    {
        Node *newnode = new Node(data);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        Node *temp = new Node(data);
        Node *curr = tail;
        while (curr->data != value)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout<<"Error"<<endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
        }
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 4);
    print(tail);
    insertNode(tail, 4, 5);
    print(tail);
    insertNode(tail, 4, 2);
    print(tail);
    deleteNode(tail, 4);
    print(tail);
    deleteNode(tail, 2);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    return 0;
}