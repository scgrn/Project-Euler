/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>
#include <cmath>
#include <vector>

typedef long long uint64;

const uint64 TARGET = 600851475143LL;

std::vector<uint64> primes;
std::vector<uint64> primeFactors;

void createListOfPrimes() {
    uint64 max = (uint64)ceil(sqrt(TARGET));

    std::cout << "Finding all prime numbers between 1 and " << max << "... ";

    bool prime[max + 1];
    for (int i = 0; i <= max; i++) {
        prime[i] = true;
    }
    
    // Sieve of Eratosthenes
    int p = 2;
    while (p * p < max) {
        if (prime[p]) {
            for (int i = p * p; i <= max; i += p) {
                prime[i] = false;
            }
        }
        p++;
    }
	
    for (int i = 2; i <= max; i++) {
		if (prime[i]) {
			primes.push_back(i);
		}
	}

    std::cout << "\nThere are " << primes.size() + 1 << " of them!\n\n";
}

void factor(uint64 target) {
    if (target == 1) return;

    for (std::vector<uint64>::iterator i = primes.begin(); i != primes.end(); i++) {
        if (target % (*i) == 0) {
            primeFactors.push_back((*i));
            std::cout << "Factoring " << (*i) << " out of " << target << "\n";
            target /= (*i);
            factor(target);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    createListOfPrimes();
    factor(TARGET);

    uint64 total = 1;
    uint64 largestFactor = 0;

    std::cout << "\nPrime factors: ";
    for (std::vector<uint64>::iterator i = primeFactors.begin(); i != primeFactors.end(); i++) {
        std::cout << (*i) << "\t";
        total *= (*i);
        if ((*i) > largestFactor) {
            largestFactor = (*i);
        }
    }

    std::cout << "\n\nTotal = " << total << "\n";
    std::cout << largestFactor << "\n";

    return 0;
}
