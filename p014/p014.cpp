/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/

#include <iostream>

typedef unsigned long long int u64;

int main(int argc, char* argv[]) {
	u64 longestChain = 0L;
	u64 longestStartingNumber = 0L;
	
	for (u64 i = 1L; i < 1000000L; i++) {
		u64 chain = 1L;
		u64 currentNumber = i;
		
		while (currentNumber != 1L) {
			if (currentNumber % 2L == 0L) {
				currentNumber /= 2L;
			} else {
				currentNumber *= 3L;
				currentNumber++;
			}				
			chain++;
		}
		if (chain > longestChain) {
			longestChain = chain;
			longestStartingNumber = i;
		}
	}
	std::cout << "Longest chain: " << longestChain << std::endl;
	std::cout << longestStartingNumber << std::endl;
	
	return 0;
}

