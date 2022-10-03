/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

*/

#include <iostream>

typedef long long uint64;

void findPrimes(int max) {
    int count = 1;  // for 2

    uint64 i = 1;
    while (count < max) {
        i += 2;
        bool composite = false;
        for (uint64 j = 3; j < i; j += 2) {
            if (i % j == 0) {
                composite = true;
                break;
            }
        }
        if (!composite) {
            count++;
        }
    }

    std::cout << i << "\n";
}

int main(int argc, char* argv[]) {
    findPrimes(10001);

    return 0;
}
