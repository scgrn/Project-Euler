/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

*/

#include <iostream>
#include <algorithm>

bool isPrime(int n) {
    if (n == 2 || n == 3) {
        return true;
    }

    if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main(int argc, char* argv[]) {
    std::string digits = "987654321";

    int largest = 0;
    for (int i = 0; i < 5; i++) {
        std::string s = digits.substr(i, std::string::npos);

        int permutations = factorial(9 - i);
        for (int permutation = 0; permutation < permutations; permutation++) {
            std::next_permutation(s.begin(), s.end());
            
            int n = stoi(s);
            if (isPrime(n)) {
                if (n > largest) {
                    largest = n;
                }
            }
        }
        if (largest > 0) {
            break;
        }
    }

    std::cout << largest << std::endl;
    
    return 0;
}
