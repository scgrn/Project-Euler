/*

Starting with the number 1 and moving to the right in a clockwise direction a
5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?

*/

#include <iostream>

const int DIM = 1001;

int main(int argc, char* argv[]) {
    int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    int dir = 0;
    
    int x = DIM / 2;
    int y = DIM / 2;
    
    int minX = x;
    int maxX = x;
    int minY = y;
    int maxY = y;
    
    int n = DIM * DIM;
    
    int total = 0;
    
    for (int i = 1; i <= n; i++) {
        if (x == y || x == (DIM - 1) - y) {
            total += i;
        }
        
        x += dirs[dir][0];
        y += dirs[dir][1];
        
        if (x < minX) {
            minX = x;
            dir++;
        }
        if (x > maxX) {
            maxX = x;
            dir++;
        }
        if (y < minY) {
            minY = y;
            dir++;
        }
        if (y > maxY) {
            maxY = y;
            dir++;
        }
        
        if (dir >= 4) {
            dir = 0;
        }
    }

    std::cout << total << std::endl;
    
    return 0;
}
