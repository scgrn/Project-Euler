/*

The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/

#include <iostream>
#include <string>
#include <algorithm>

std::string intToBinary(int n) {
    if (n == 0) {
        return "0";
    }
    
    std::string binary;
    while (n > 0) {
        binary += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    
    std::reverse(binary.begin(), binary.end());
    return binary;
}

bool isPalindrome(std::string str) {
    std::string rev = str;
    reverse(rev.begin(), rev.end());
    
    return rev == str;
}

int main(int argc, char* argv[]) {
    int sum = 0;
    
    for (int i = 0; i < 1000000; i++) {
        std::string str = std::to_string(i);
        if (isPalindrome(str)) {
            std::string binary = intToBinary(i);
            if (isPalindrome(binary)) {
                sum += i;
            }
        }
    }
    std::cout << sum << std::endl;
    
    return 0;
}
