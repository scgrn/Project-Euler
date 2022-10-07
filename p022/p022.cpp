/*

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
	std::fstream input;
	input.open("p022/p022_names.txt");
	
	std::string line;
	getline(input, line);
	input.close();
	std::stringstream ss(line);
	
	std::string name;
	std::vector<std::string> names;
	while (getline(ss, name, ',')) {
		name = name.substr(1, name.size() - 2);
		names.push_back(name);
	}
	
	std::sort(names.begin(), names.end());
	
	unsigned long total = 0;
	int index = 1;
	for (std::string name : names) {
		int score = 0;
		for (int i = 0; i < name.size(); i++) {
			score += (int)name[i] - 64;
		}
		score *= index;
		total += score;
		
		index++;
	}
	
	std::cout << total << std::endl;
	
	return 0;
}
