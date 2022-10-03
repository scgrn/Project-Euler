/*

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include <iostream>

#include "../shared/bigInteger.h"

const int SIZE = 20;

BigInteger Factorial(int n){
	BigInteger f(1);
	for (int i = 2; i <= n; i++) {
		f *= i;
	}
	return f;
}

// (n*2)! / n!n!
int main(int argc, char* argv[]) {
	std::cout << Factorial(SIZE * 2) / (Factorial(SIZE) * Factorial(SIZE)) << std::endl;

	return 0;
}
