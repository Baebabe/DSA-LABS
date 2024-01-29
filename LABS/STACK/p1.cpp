#include <iostream>
using namespace std;

int stack[5];
int top = 0;
int Max = 5;

void Push_Stack(int item)
{
    if (top == Max)
    {
        cout << "STACK IS FULL, OVERFLOW" << endl;
        return;
    }
    else
    {
        stack[top] = item;
        cout << "Pushing " << item << " into the stack." << endl;
        top = top + 1;
    }
}

int Pop_Stack()
{
    if (top == 0)
    {
        cout << "STACK IS EMPTY" << endl;
        return -1;
    }
    else
    {
        return stack[--top];
    }
}

int main()
{
    Push_Stack(5);
    Push_Stack(12);
    // Push_Stack(13);
    // Push_Stack(15);
    // Push_Stack(51);
    int poppedValue;

    while ((poppedValue = Pop_Stack()) != -1)
    {
        cout << "Popped value: " << poppedValue << endl;
    }

    return 0;
}
