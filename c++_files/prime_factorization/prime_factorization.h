#include <vector>
#include <math.h>

using namespace std;

vector<long long> find_prime_factors(long long n)
{
    vector<long long> vec;
    while (n % 2 == 0)
    {
        vec.push_back(2);
        n = n / 2;
    }
    for (long long i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            vec.push_back(i);
            n = n / i;
        }
    }

    if( n > 2 ) {
        vec.push_back(n);
    }
    return vec;
}