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

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertatpositionb(Node *&tail, Node *&head, int position, int d)
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
    // if (temp->next == NULL)
    // {
    //     insertattail(tail, d);
    //     return;
    // }
    Node *Nodetoinsert = new Node(d);
    Nodetoinsert->next = temp->next;
    temp->next = Nodetoinsert;
}
void insertatpositiona(Node *&tail, Node *&head, int position, int d)
{

    // if (position == 1)
    // {
    //     insertathead(head, d);
    //     return;
    // }
    Node *temp = head;
    int count = 1;
    while (count < position)
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
    temp->next = Nodetoinsert;
}

void deleteNodeatbeg(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count <= position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
} 

void deleteNodeatend(Node *&head)
{
 Node *prev = nullptr;
    Node *curr= head;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    delete curr;
    prev->next = nullptr;
}


void print(Node *&head)
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
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // insertathead(head, 12);
    // print(head);
    // insertathead(head, 15);
    // print(head);
    insertattail(tail, 12);
    print(head);
    insertattail(tail, 15);
    print(head);
    insertatpositionb(tail, head, 3, 34);
    print(head);
    insertatpositionb(tail, head, 1, 30);
    print(head);
    insertatpositionb(tail, head, 5, 32);
    print(head);
    insertatpositiona(tail, head, 3, 36);
    print(head);
    insertatpositiona(tail, head, 1, 38);
    print(head);
    insertatpositiona(tail, head, 8, 39);
    print(head);
    deleteNode(8, head);
    print(head);
    deleteNodeatbeg(head);
    print(head);
    deleteNodeatend(head);
    print(head);
    return 0;
}