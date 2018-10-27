int even_fib(int n)
{
    if (n < 1)
    {
        return n;
    }
    if (n == 1)
    {
        return 2;
    }
    return (4 * even_fib(n-1) + even_fib(n-2));
}