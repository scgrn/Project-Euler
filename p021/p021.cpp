/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <iostream>
#include <cmath>

int sumOfDivisors(int num) {
	if(num == 1) {
		return 0;
	}

	int result = 0;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			if (i == (num / i)) {
				result += i;
			} else {
				result += (i + num / i);
			}
		}
	}
	
	return (result + 1);
}

int main(int argc, char* argv[]) {
	bool amicable[10000];
	for (int i = 0; i < 10000; i++) {
		amicable[i] = false;
	}
	
	for (int i = 2; i < 10000; i++) {
	   if (!amicable[i]) {
		   int sum = sumOfDivisors(i);
		   if (sum != i && sumOfDivisors(sum) == i) {
			   amicable[i] = true;
			   amicable[sum] = true;
		   }
	   }
	}

	int total = 0;
	for (int i = 0; i < 10000; i++) {
		if (amicable[i]) {
			total += i;
		}
	}
	
	std::cout << total << std::endl;
	
	return 0;
}
