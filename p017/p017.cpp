/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/

#include <iostream>

std::string ONES[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

std::string TENS[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

std::string toEnglish(int n) {
    if (n > 0 && n < 20) {
        return ONES[n];
    }
    if (n >= 20 && n < 100) {
        return TENS[n / 10] + (n % 10 != 0 ? ONES[n % 10] : "");
    }
    if (n >= 100 && n < 1000) {
        return ONES[n / 100] + "hundred" + (n % 100 != 0 ? "and" + toEnglish(n % 100) : "");
    }
    if (n >= 1000 && n < 1000000) {
        return toEnglish(n / 1000) + "thousand" + (n % 1000 != 0 ? toEnglish(n % 1000) : "");
    }
    
    return "";
}

int main(int argc, char* argv[]) {
    int sum = 0;
    
    for (int i = 1; i <= 1000; i++) {
        sum += toEnglish(i).length();
    }
    std::cout << sum << std::endl;
    
    return 0;
}
