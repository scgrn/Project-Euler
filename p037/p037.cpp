/*

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/

#include <iostream>

const int MAX = 1000000;

bool prime[MAX];

void sieveOfEratosthenes() {
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;

    int p = 2;
    while (p * p < MAX) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX; i += p) {
                prime[i] = false;
            }
        }
        p++;
    }
}

bool truncatablePrime(int n) {
    std::string s = std::to_string(n);
    
    for (int i = 1; i < s.length(); i++) {
        if (!prime[stoi(s.substr(i, std::string::npos))]) {
            return false;
        }
        if (!prime[stoi(s.substr(0, s.length() - i))]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    sieveOfEratosthenes();

    int sum = 0;
    int count = 0;
    for (int i = 13; i <= MAX; i++) {
        if (prime[i]) {
            if (truncatablePrime(i)) {
                sum += i;
                count++;
                if (count == 11) {
                    break;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    
    return 0;
}

