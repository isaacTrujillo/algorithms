#include <vector>
#include <cstring>

using namespace std;

vector<long long> sieve(long long n)
{
    bool primes[n + 1];
    vector<long long> res;
    memset(primes, true, sizeof(primes));
    for (long long i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (long long j = i * 2; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    for (long long i = 2; i <= n; i++)
    {
        if(primes[i]) {
            res.push_back(i);
        }
    }
    return res;
}