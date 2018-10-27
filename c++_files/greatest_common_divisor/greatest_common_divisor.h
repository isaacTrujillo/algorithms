#include "../prime_factorization/prime_factorization.h"
#include <vector>

using namespace std;
long long gcd(long long a, long long b) {
    long long res = 1;
    vector<long long> primes_a = find_prime_factors(a);
    vector<long long> primes_b = find_prime_factors(b);
    for(long long i = 0; i < primes_a.size() && primes_b.size(); i++) {
        if(primes_a[i] == primes_b[i]) {
            res *= primes_a[i];
        }
    }
    return res;
}