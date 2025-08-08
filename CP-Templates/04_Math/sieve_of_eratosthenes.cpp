#include <vector>

std::vector<int> sieve_of_eratosthenes(int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; ; ++i) {
        int sq = i * i;
        if (sq > n) break;

        if (prime[i]) {
            for (int j = sq; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) primes.push_back(i);
    }
    return primes;
}