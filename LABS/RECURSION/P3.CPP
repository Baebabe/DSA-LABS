#include <iostream>
using namespace std;


int tail_factorial(int n, int num = 1)
{
    if (n == 0)
    {
        return num;
    }
    else
    {
        return tail_factorial(n - 1, n * num);
    }
}
int tail_fibonacci(int n, int a = 0, int b = 1)
{
    if (n == 0)
    {
        return a;
    }
    if (n == 1)
    {
        return b;
    }
    return tail_fibonacci(n - 1, b, a + b);
}
int factorial(int num){
    return tail_factorial(num);
}
int fibonacci(int num){
    return tail_fibonacci(num);
}
int main()
{
    cout << factorial(3) << endl;
    cout << factorial(5) << endl;
    cout << fibonacci(5) << endl;
    cout << fibonacci(0) << endl;
    cout << fibonacci(1) << endl;
    cout << fibonacci(2) << endl;
    return 0;
}