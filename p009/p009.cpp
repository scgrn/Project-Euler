/*

A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include <iostream>

typedef long long uint64;

int main(int argc, char* argv[]) {
    for (int a = 1; a < 1000; a++) {
        for (int b = 1; b < 1000; b++) {
            for (int c = 1; c < 1000; c++) {
                if (((a + b + c) == 1000) && ((a * a) + (b * b) == (c * c))) {
                    std::cout << "a = " << a << "\n";
                    std::cout << "b = " << b << "\n";
                    std::cout << "c = " << c << "\n\n";
                    int product = a * b * c;
                    std::cout << product << "\n";

                    return 0;
                }
            }
        }
    }

    return 0;
}






