/*

The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?

*/

#include <iostream>

typedef long long uint64;
int divisors(uint64 x) {
    uint64 limit = x;
    int numberOfDivisors = 0;

    for (uint64 i = 1; i < limit; i++) {
        if (x % i == 0) {
            limit = x / i;

            //  check for perfect squares
            if (limit != i) {
                numberOfDivisors++;
            }
            numberOfDivisors++;
        }
    }

    return numberOfDivisors;
}

int main(int argc, char* argv[]) {
    uint64 total = 0;
    int i = 1;

    while (true) {
        total += i;
        i++;
        if (divisors(total) > 500) {
            std::cout << total << "\n";
            break;
        }
    }

    return 0;
}








