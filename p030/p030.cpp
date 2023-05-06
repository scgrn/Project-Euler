/*

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 44
8208 = 8^4 + 2^4 + 0^4 + 84
9474 = 9^4 + 4^4 + 7^4 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/

#include <iostream>
#include <cmath>

const int exponent = 5;

int powerSum(int n) {
    int sum = 0;
    
    while (n > 0) {
        sum += pow((n % 10), exponent);
        n = n / 10;
    }
    
    return sum;
}

int main(int argc, char* argv[]) {
    int lowerBound = powerSum(2) * 2;
    int upperBound = powerSum(9) * exponent;
    
    int sum = 0;
    for (int i = lowerBound; i <= upperBound; i++) {
        if (powerSum(i) == i) {
            sum += i;
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}
