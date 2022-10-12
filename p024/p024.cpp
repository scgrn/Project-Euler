/*

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If
all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0,
1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

*/

#include <iostream>
#include <algorithm>

int main(int argc, char* argv[]) {
	std::string s = "0123456789";
	
	for (int i = 1; i < 1000000; i++ ) {
                std::next_permutation(s.begin(), s.end());
        }
        std::cout << std::stoul(s) << std::endl;

	return 0;
}
