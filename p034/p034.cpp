/*
 
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

*/

#include <iostream>

int factorial[10];

bool equal(int n) {
    std::string s = std::to_string(n);

    int sum = 0;
    for (char c : s) {
        int digit = c - '0';
        sum += factorial[digit];
    }

    return sum == n;
}

int main(int argc, char* argv[]) {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= 9; i++) {
        factorial[i] = i * factorial[i - 1];
    }
    
    int sum = 0;
    for (int i = 3; i < 2000000; i++) {
        if (equal(i)) {
            sum += i;
        }
    }
    
    std::cout << sum << std::endl;
}
