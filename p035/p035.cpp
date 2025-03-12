/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2,3,5,7,11,13,17,31,37,71,73,79, and 97.

How many circular primes are there below one million?

*/

#include <iostream>

const int MAX = 1000000;

bool prime[MAX];

void sieveOfEratosthenes() {
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }

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

bool isCircularPrime(int n) {
    std::string s = std::to_string(n);

    for (int i = 0; i < s.length(); i++) {
        std::string rotation = s.substr(i) + s.substr(0, i);
        int value = stoi(rotation);
        if (!prime[value]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    sieveOfEratosthenes();

    int total = 0;
    for (int i = 2; i < MAX; i++) {
        if (isCircularPrime(i)) {
            total++;
        }
    }
    
    std::cout << total << std::endl;
}
