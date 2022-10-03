/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

#include <iostream>

#include "../shared/bigInteger.h"

int main(int argc, char* argv[]) {
	BigInteger a(2);
	a ^= 1000;
	
	int sum = 0;
	for (int i = 0; i < Length(a); i++) {
		sum += a[i];
	}
	
	std::cout << sum << std::endl;
	
	return 0;
}
