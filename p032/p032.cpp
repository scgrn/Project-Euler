/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 
1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> permutations;

void recursePermutation(int index, std::string &s) {
    if (index == s.size()) {
        permutations.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        std::swap(s[index], s[i]);
        recursePermutation(index + 1, s);
        std::swap(s[index], s[i]);
    }
}

int sumPandigitalProducts() {
    std::unordered_map<int, bool> products;
    int sum = 0;

    for (std::string s : permutations) {
        for (int partition1 = 1; partition1 < 6; partition1++) {
            for (int partition2 = partition1 + 1; partition2 < 7; partition2++) {
                int multiplicand = stoi(s.substr(0, partition1));
                int multiplier = stoi(s.substr(partition1, partition2 - partition1));
                int product = stoi(s.substr(partition2, std::string::npos));
                
                if (multiplicand * multiplier == product) {
                    if (products.find(product) == products.end()) {
                        products[product] = true;
                        sum += product;
                    }
                }
            }
        }
    }

    return sum;
}

int main(int argc, char* argv[]) {
    std::string digits = "123456789";

    recursePermutation(0, digits);
    std::cout << sumPandigitalProducts() << std::endl;

    return 0;
}
