#include <iostream>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    Node(int coeff, int exp)
    {
        this->coefficient = coeff;
        this->exponent = exp;
        this->next = NULL;
    }
};

void insertitem(Node *&head, int coeff, int exp)
{
    Node *newnode = new Node(coeff, exp);
    if (head == NULL || exp > head->exponent)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL && (temp->next->exponent) > exp)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

Node *addpolynomial(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 != NULL || poly2 != NULL)
    {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : -10000000000000;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 10000000000000;

        if (exp1 > exp2)
        {
            insertitem(result, coeff1, exp1);
            if (poly1 != NULL)
                poly1 = poly1->next;
        }
        else if (exp1 < exp2)
        {
            insertitem(result, coeff2, exp2);
            if (poly2 != NULL)
                poly2 = poly2->next;
        }
        else
        {
            insertitem(result, coeff1 + coeff2, exp1);
            if (poly1 != NULL)
                poly1 = poly1->next;
            if (poly2 != NULL)
                poly2 = poly2->next;
        }
    }
    return result;
}

void show(Node *poly)
{
    while (poly != NULL)
    {
        cout << poly->coefficient << "x^" << poly->exponent;
        poly = poly->next;
        if (poly != NULL)
        {
            cout << "+";
        }
    }
    cout << endl;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    insertitem(poly1, 3, 5);
    insertitem(poly1, 3, 2);
    insertitem(poly1, 3, 3);
    insertitem(poly2, 3, 5);
    insertitem(poly2, 3, 1);
    insertitem(poly2, 3, 6);
    show(addpolynomial(poly1, poly2));
    return 0;
}
