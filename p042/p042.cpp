/*

The nth term of the sequence of triangle numbers is given by, t_n = 1/2n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t_10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

bool isTriangleNumber(int x) {
    if (x < 0) {
        return false;
    }

    //  calculate the discriminant of the quadratic formula
    int discriminant = 1 + 8 * x;
    
    //  check if discriminant is a perfect square
    int sqrtDiscriminant = static_cast<int>(sqrt(discriminant));
    if (sqrtDiscriminant * sqrtDiscriminant != discriminant) {
        return false;
    }

    //  check if n is a valid integer and n > 0
    int n = (-1 + sqrtDiscriminant) / 2;
    return n * (n + 1) / 2 == x;
}

bool isTriangleWord(std::string word) {
    int value = 0;
    for (char c : word) {
        value += c - 'A' + 1;
    }
    
    return isTriangleNumber(value);
}

int main(int argc, char* argv[]) {
    std::string line;
    std::ifstream file("p042/0042_words.txt");

    if (file.is_open()) {
        int total = 0;

        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            while (getline(ss, word, ',')) {
                word = word.substr(1, word.length() - 2);
                if (isTriangleWord(word)) {
                    total++;
                }
            }
        }
        file.close();

        std::cout << total << std::endl;
    } else {
        std::cout << "Couldn't read input!" << std::endl;
    }

    return 0;
}
