//doubly linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
    }
};

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertatposition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    Node *Nodetoinsert = new Node(d);
    Nodetoinsert->next = temp->next;
    temp->next->prev = Nodetoinsert;
    temp->next = Nodetoinsert;
    Nodetoinsert->prev = temp;
}

void deletefrombeg(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deletefromend(Node *&head)
{
    Node *before = NULL;
    Node *curr = head;
    while (curr->next != NULL)
    {
        before = curr;
        curr = curr->next;
    }
    delete curr;
    before->next = NULL;
}

void deletefromposition(Node *&head, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *before = NULL;
        Node *curr = head;
        int count = 1;
        while (count <position)
        {
            before = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        before->next = curr->next;
        curr->next->prev = before;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(12);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertathead(head, 13);
    print(head);
    insertattail(tail, 16);
    print(head);
    insertatposition(head, tail, 1, 14);
    print(head);
    insertatposition(head, tail, 3, 15);
    print(head);
    insertatposition(head, tail, 6, 18);
    print(head);
    deletefrombeg(head);
    print(head);
    deletefromend(head);
    print(head);
    deletefromposition(head, 3);
    print(head);
    deletefromposition(head, 1);
    print(head);
    return 0;
}