/*

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2    =     0.5
1/3    =     0.(3)
1/4    =     0.25
1/5    =     0.2
1/6    =     0.1(6)
1/7    =     0.(142857)
1/8    =     0.125
1/9    =     0.(1)
1/10    =     0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

*/

#include <iostream>
#include <map>

int fractionalCycleLength(int dividend, int divisor) {
    std::string result;
    std::map<int, bool> remainderMap;

    int remainder = dividend % divisor;

    //    repeat until remainder is 0 or cycle repeats
    while ((remainder != 0) && (remainderMap.find(remainder) == remainderMap.end())) {
        remainderMap[remainder] = result.length();

        remainder = remainder * 10;
        result += std::to_string(remainder / divisor);
 
        remainder = remainder % divisor;
    }
 
    return (remainder == 0) ? 0 : result.substr(remainderMap[remainder]).length();
}

int main(int argc, char* argv[]) {
    int maxCycleLength = -1;
    int maxIndex = -1;
    
    for (int i = 1; i < 1000; i++) {
        int result = fractionalCycleLength(1, i);
    
        if (result > maxCycleLength) {
            maxCycleLength = result;
            maxIndex = i;
        }
    }
    std::cout << maxIndex << std::endl;
    
    return 0;
}
