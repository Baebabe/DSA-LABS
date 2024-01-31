
#include <iostream>
using namespace std;

class Static_List
{
public:
    struct Node
    {
        int value;
        int next;
    };
    Node *nodes;
    int avail, head, tail;

    Static_List(int capacity)
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

    void insertAtBeginning(int value)
    {
        if (avail == -1)
        {
            return;
        }

        int new_node = avail;
        avail = nodes[avail].next;

        nodes[new_node].value = value;
        nodes[new_node].next = head;
        head = new_node;

        if (tail == -1)
        {
            tail = new_node;
        }
    }

    void insertAtEnd(int value)
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

    void deleteFromBeginning()
    {
        if (head == -1)
        {
            return;
        }

        int value = nodes[head].value;
        int to_del = head;
        head = nodes[head].next;

        nodes[to_del].next = avail;
        avail = to_del;
        cout << "Deleted node's value: " << value << '\n';
    }

    void deleteFromEnd()
    {
        if (head == -1)
        {
            return;
        }
        int value = nodes[tail].value;
        int to_del = tail;
        // Single node case
        if (head == tail)
        {
            head = tail = -1;
        }
        else
        { 
            int curr = head;
            while (nodes[curr].next != tail)
            {
                curr = nodes[curr].next;
            }
            tail = curr;
            nodes[curr].next = -1;
        }
        nodes[to_del].next = avail;
        avail = to_del;

        cout << "Deleted node's value: " << value << '\n';
    }

    void insert_after(int idx, int value)
    {
        if (avail == -1)
        {
            return;
        }

        int new_node = avail;
        avail = nodes[avail].next;

        nodes[new_node].value = value;
        nodes[new_node].next = nodes[idx].next;
        nodes[idx].next = new_node;

        if (tail == idx)
        {
            tail = new_node;
        }
    }

    void del_after(int idx)
    {
        if (nodes[idx].next == -1)
        {
            return;
        }
        
        int to_del = nodes[idx].next;
        nodes[idx].next = nodes[to_del].next;

        nodes[to_del].next = avail;
        avail = to_del;

        if (tail == to_del)
        {
            tail = idx;
        }
    }

    void print()
    {
        if (head == -1)
        {
            return;
        }

        int curr = head;
        while (curr != -1)
        {
            cout << nodes[curr].value << " ";
            curr = nodes[curr].next;
        }

        cout << "-1\n";
    }
};

int main()
{
    Static_List list(10);
    list.insertAtBeginning(6);
    list.insertAtEnd(1);
    list.insert_after(1, 5);
    list.insert_after(5, 8);
    list.print();
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.del_after(1);
    list.print();
    return 0;
}