#include <iostream>
using namespace std;
int factorial(int n, int num = 1)
{
    if (n == 0)
    {
        return num;
    }
    else
    {
        return factorial(n - 1, n * num);
    }
}
int fibonacci(int n, int a = 0, int b = 1)
{
    if (n == 0)
    {
        return a;
    }
    if (n == 1)
    {
        return b;
    }
    return fibonacci(n - 1, b, a + b);
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