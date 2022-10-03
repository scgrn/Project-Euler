/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <iostream>

bool palindrome(std::string const& str) {
    int length = str.length();
    for (int i = 0; i < (length / 2); i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    int largest = 0;

    for (int i = 999; i > 0; i--) {
        for (int j = 999; j > 0; j--) {
            int num = i * j;
            if (num > largest) {
                if (palindrome(std::to_string(num))) {
                    largest = num;
                }
            }
        }
    }

    std::cout << largest << "\n";

    return 0;
}

