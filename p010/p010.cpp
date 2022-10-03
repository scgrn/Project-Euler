/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <iostream>

int main(int argc, char* argv[]) {
    int n = 2000000;
    
    bool prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    // Sieve of Eratosthenes
    int p = 2;
    while (p * p < n) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
        p++;
    }
    
    long long total = 0L;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            total += i;
        }
    }
    std::cout << total << std::endl;

    return 0;
}
