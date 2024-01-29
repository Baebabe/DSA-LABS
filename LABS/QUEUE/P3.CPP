#include <iostream>
using namespace std;
class deque
{
private:
    int *arr;
    int front, rear;
    int size;

public:
    deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool pushrear(int value)
    {
        if (isfull())
        {
            return false;
        }
        else if (isempty())
        {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool pushfront(int value)
    {
        if (isfull())
        {
            return false;
        }
        else if (isempty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }


int popfront(){
        if(isempty()){
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if(front ==rear){
            front =rear=-1;
        }
        else if(front==size-1){
            front =0;
        }
        else{
            front++;
        }
        return ans;
    }

    
int poprear(){
        if(isempty()){
            return -1;
        }
        int ans=arr[rear];
         arr[rear]=-1;
        if(front ==rear){
            front =rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    bool isfull()
    {
        if ((front == 0 && rear == size - 1 )|| (rear == (front-1)%(size-1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isempty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
deque q(3);
q.pushrear(10);
q.pushfront(12);
q.pushfront(14);
cout<<q.popfront()<<endl;
cout<<q.poprear()<<endl;

    return 0;
}