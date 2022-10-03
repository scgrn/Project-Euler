/*

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

#include <iostream>

#include "../shared/bigInteger.h"

int main(int argc, char* argv[]) {
	BigInteger a(1);

	for (int i = 1; i <= 100; i++) {
		a *= i;
	}

	int sum = 0;
	for (int i = 0; i < Length(a); i++) {
		sum += a[i];
	}
	
	std::cout << sum << std::endl;

	return 0;
}
