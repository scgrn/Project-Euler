/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on. In this way, we note the following:

d_2 x d_3 x d_4 = 406 is divisible by 2
d_3 x d_4 x d_5 = 063 is divisible by 3
d_4 x d_5 x d_6 = 635 is divisible by 5
d_5 x d_6 x d_7 = 357 is divisible by 7
d_6 x d_7 x d_8 = 572 is divisible by 11
d_7 x d_8 x d_9 = 728 is divisible by 13
d_8 x d_9 x d_10 = 289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstdint>

bool hasProperty(std::string s) {
    const std::unordered_map<int, int> PRODUCT = {
        {2, 2},
        {3, 3},
        {4, 5},
        {5, 7},
        {6, 11},
        {7, 13},
        {8, 17},
    };

    for (auto p : PRODUCT) {
        int i = stoi(s.substr(p.first - 1, 3));
        if (i % p.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char* argv[]) {
    std::string s = "0123456789";

    uint64_t sum = 0;
    
    bool done = false;
    while (!done) {
        if (hasProperty(s)) {
            sum += stoul(s);
        }
        done = !std::next_permutation(s.begin(), s.end());
    }
    std::cout << sum << std::endl;
    
    return 0;
}
