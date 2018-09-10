#include <iostream>

using namespace std;

bool isOdd(int n)
{
    return n & 1 ? true : false;
}
bool isEven(int n)
{
    return !isOdd(n);
}
double power(double x, int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
    {
        return 1 / power(x,(n * -1));
    }
    
    if (isOdd(n))
    {
        return power(x, n - 1) * x;
    }
    
    if (isEven(n))
    {
        double res = power(x, n / 2);
        return res * res;
    }
    
    return 0.0;
};
int main()
{
    cout << power(2.000000,-2);
    return 0;
}