/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

*/

#include <iostream>
#include <numeric>

int main(int argc, char* argv[]) {
    int productNumerator = 1;
    int productDenominator = 1;

    for (int numerator = 11; numerator < 100; numerator++) {
        for (int denominator = numerator + 1; denominator < 100; denominator++) {
            int n1 = numerator / 10;
            int n2 = numerator % 10;
            int d1 = denominator / 10;
            int d2 = denominator % 10;
            
            if (n2 == 0 || d2 == 0) {
                continue;
            }

            int newNumerator = -1;
            int newDenominator = -1;
            
            //  remove common digit from both
            if (n1 == d1) {
                newNumerator = n2;
                newDenominator = d2;
            }
            
            if (n1 == d2) {
                newNumerator = n2;
                newDenominator = d1;
            }

            if (n2 == d1) {
                newNumerator = n1;
                newDenominator = d2;
            }

            if (n2 == d2) {
                newNumerator = n1;
                newDenominator = d1;
            }

            if (newNumerator != -1 && newDenominator != -1) {
                float expected = (float)numerator / (float)denominator;
                float result = (float)newNumerator / (float)newDenominator;
                if (result == expected) {
                    productNumerator *= newNumerator;
                    productDenominator *= newDenominator;
                }
            }
        }
    }
    
    int gcd = std::gcd(productNumerator, productDenominator);
    std::cout << (productDenominator / gcd) << std::endl;
    
    return 0;
}
