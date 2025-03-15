/*

Take the number 192 and multiply it by each of 1, 2, and 3:

192 x 1 = 192
192 x 2 = 384
192 x 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ..., n) where n > 1?

*/

#include <iostream>

std::string concatenate(int integer, int n) {
    std::string s;
    
    for (int i = 1; i <= n; i++) {
        s += std::to_string(integer * i);
    }
    
    return s;
}

bool pandigital(std::string s) {
    if (s.length() != 9) {
        return false;
    }

    bool digit[10];
    for (int i = 0; i < 10; i++) {
        digit[i] = false;
    }
    
    for (char c : s) {
        digit[c - '0'] = true;
    }

    for (int i = 1; i < 10; i++) {
        if (!digit[i]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    int largest = 0;

    bool done = false;

    int anInteger = 1;
    while (!done) {
        int n = 2;
        std::string concatenated = concatenate(anInteger, n);
        int length = concatenated.length();
        if (length > 9) {
            done = true;
        }
        while (length <= 9) {
            std::string concatenated = concatenate(anInteger, n);
            length = concatenated.length();
            if (pandigital(concatenated)) {
                int value = stoi(concatenated);
                if (value > largest) {
                    largest = value;
                }
            }
            n++;
        }
        anInteger++;
    }
    std::cout << largest << std::endl;

    return 0;
}
