/*

If p is the perimeter of a right angle triangle with integral length sides, a, b, c, there are exactly three solutions for p = 120.

20,48,52, 24,45,51, 30,40,50

For which value of p < 1000, is the number of solutions maximised?

*/

#include <iostream>
#include <cassert>
#include <unordered_map>
#include <cmath>

std::unordered_map<int, int> ps;

void findPerimiters() {
    for (int a = 0; a < 333; a++) {
        for (int b = a; b < 1000 - (a * 2); b++) {
            float c = sqrt((a * a) + (b * b));
            if (fmod(c, 1.0f) == 0.0f) {
                int p = a + b + (int)c;
                if (p < 1000) {
                    if (ps.find(p) == ps.end()) {
                        ps[p] = 1;
                    } else {
                        ps[p]++;
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    findPerimiters();

    int largestP = 0;
    int largestIndex = 0;
    for (auto it = ps.begin(); it != ps.end(); it++) {
        if (it->second > largestP) {
            largestP = it->second;
            largestIndex = it->first;
        }
    }
    std::cout << largestIndex << std::endl;

    return 0;
}
