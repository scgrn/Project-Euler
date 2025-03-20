/*

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317$.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

*/

#include <iostream>

#include "../shared/bigInteger.h"

BigInteger calculateSeries(int limit) {
    BigInteger n;

    for (int i = 1; i < limit; i++) {
        BigInteger bi(i);
        n += (bi ^ bi);
    }

    return n;
}

int main(int argc, char* argv[]) {
    std::stringstream ss;
    ss << calculateSeries(1000);
    std::string s = ss.str();
    std::cout << s.substr(s.length() - 10, 10) << std::endl;

    return 0;
}

