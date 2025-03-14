/*

An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.
d_1 d_10 d_100 d_1000 d_10000 d_100000 d_1000000

*/

#include <iostream>

int main(int argc, char* argv[]) {
    std::string s;
    
    int n = 1;
    while (s.length() <= 1000000) {
        s += std::to_string(n);
        n++;
    }
    
    int product = 1;
    int digit = 1;
    for (int digit = 1; digit <= 1000000; digit *= 10) {
        product *= s[digit - 1] - '0';
    }
    
    std::cout << product << std::endl;

    return 0;
}

