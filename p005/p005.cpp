/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include <iostream>

typedef long long uint64;

bool divisible(uint64 num) {
    for (uint64 i = 1; i <= 20; i++) {
        if (num % i != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    uint64 max = 1;
    for (int i = 1; i <= 20; i++) {
        max *= i;
    }
    std::cout << "Max = " << max << "\n";

    for (uint64 i = 1; i <= max; i++) {
        if (divisible(i)) {
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}


