//singly linked list
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

void inserbeforenode(Node *&tail, Node *&head, int value, int d)
{
    Node *temp = head;
    if (temp->data == value)
    {
        insertathead(head, d);
        return;
    }
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    Node *Nodetoinsert = new Node(d);
    Nodetoinsert->next = temp->next;
    temp->next = Nodetoinsert;
}
void insertafternode(Node *&tail, Node *&head, int value, int d)
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
    temp->next = Nodetoinsert;
}

void deleteNodeatbeg(Node *&head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteNodebefore(int value, Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    if(head->data==value){
        cout<<"Cant delete node before this"<<endl;
         exit(0);
    }
    while (curr->next->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void deleteNodeafter(int value, Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    if(curr->next==NULL){
        cout<<"Cant delete node after this node"<<endl;
        exit(0);
    }
    Node *temp1 = curr->next;
    curr->next = temp1->next;
    temp1->next = NULL;
    delete temp1;
}

void deleteNodeatend(Node *&head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr->next != nullptr)
    {
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
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertathead(head, 12);
    print(head);
    insertattail(tail, 15);
    print(head);
    inserbeforenode(tail, head, 15, 34);
    print(head);
    // inserbeforenode(tail, head, 34, 38);
    // print(head);
    // inserbeforenode(tail, head, 10, 28);
    // print(head);
    insertafternode(tail, head, 34, 36);
    print(head);
    // insertafternode(tail, head, 10, 42);
    // print(head);
    deleteNodeatbeg(head);
    print(head);
    deleteNodeatend(head);
    print(head);
    // deleteNodebefore(42, head);
    // print(head);
    // deleteNodeafter(34, head);
    // print(head);
    deleteNodeafter(34, head);
    print(head);
    return 0;
}
