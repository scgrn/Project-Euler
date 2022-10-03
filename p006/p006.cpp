/*

The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

#include <iostream>

typedef long long uint64;

uint64 sumOfSquares(int count) {
    uint64 sum = 0;

    for (int i = 1; i <= count; i++) {
        sum += (i * i);
    }

    return sum;
}

uint64 squareOfSum(int count) {
    uint64 sum = 0;

    for (int i = 1; i <= count; i++) {
        sum += i;
    }

    return (sum * sum);
}

int main(int argc, char* argv[]) {
    int count = 100;

    uint64 answer = squareOfSum(count) - sumOfSquares(count);
    std::cout << answer << "\n";

    return 0;
}



