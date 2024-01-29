#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}
int main()
{
    cout << fibonacci(5) << endl;
    cout << fibonacci(0) << endl;
    cout << fibonacci(1) << endl;
    cout << fibonacci(2) << endl;
    return 0;
}