// doubly linked list
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

void insertbeforevalue(Node *&head, Node *&tail, int value, int d)
{
    if (head->data == value)
    {
        insertathead(head, d);
        return;
    }
    Node *temp = head;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
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

void insertaftervalue(Node *&head, Node *&tail, int value, int d)
{
    Node *temp = head;
    while (temp->data != value)
    {
        temp = temp->next;
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

void deletebeforevalue(Node *&head, int value)
{
    if (head->next->data == value)
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
        while (curr->next->data != value)
        {
            before = curr;
            curr = curr->next;
        }
        if (curr->next == nullptr)
        {
            return;
        }
        curr->prev = NULL;
        before->next = curr->next;
        curr->next->prev = before;
        curr->next = NULL;
        delete curr;
    }
}

void deleteaftervalue(Node *&head, int value)
{
    Node *curr = head;
    while (curr->data != value)
    {
        curr = curr->next;
    }
    if (curr == nullptr || curr->next == nullptr)
    {
        return;
    }
    Node *temp = curr->next;
    temp->prev = NULL;
    curr->next = temp->next;
    temp->next->prev = curr;
    temp->next = NULL;
    delete temp;
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
    insertbeforevalue(head, tail, 13, 14);
    print(head);
    insertbeforevalue(head, tail, 14, 15);
    print(head);
    insertbeforevalue(head, tail, 16, 11);
    print(head);
    insertaftervalue(head, tail, 15, 25);
    print(head);
    insertaftervalue(head, tail, 16, 20);
    print(head);
    deletefrombeg(head);
    print(head);
    deletefromend(head);
    print(head);
    deletebeforevalue(head, 14);
    print(head);
    deletebeforevalue(head, 13);
    print(head);
    deleteaftervalue(head, 12);
    print(head);
    deleteaftervalue(head, 13);
    print(head);
    return 0;
}