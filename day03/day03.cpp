#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

uint32_t get_score(char ch ) {
	uint32_t val = 0;
	if (ch >= 'A' && ch <= 'Z') {
		val =  ch - 'A' + 27;
	} else {
		val =  ch - 'a' + 1;
	}
	//std::cout << "val of " << ch << " is " << val << std::endl;
	return val;
}

uint32_t do_first(){
	std::ifstream infile("input03.txt");
	std::string line;
	uint32_t total1 = 0;
	while( std::getline(infile, line)) {
		std:: unordered_set<char> items1;
		std::string first = line.substr(0,line.length()/2);
		std::string second = line.substr(line.length()/2,line.length());
		//std::cout << "first: " << first << " second: " << second << std::endl;
		for (auto &ch : first) {
			items1.insert(ch);
		}
		for (auto &ch : second) {
			if (items1.find(ch) != items1.end()) {
				total1 += get_score(ch);
				break;
			}
		}
	}
	std::cout << "first score is " << total1 << std::endl;
	return total1;
}

uint32_t do_second(){
	uint32_t total2 = 0;
	std::ifstream infile("input03.txt");
	std::string line1;
	std::string line2;
	std::string line3;
	while ( std::getline(infile, line1)&&
		std::getline(infile, line2)&&
		std::getline(infile, line3)) {
		std::unordered_set<char> items1;
		std::unordered_set<char> items2;
		std::unordered_set<char> items3;

		for (auto &ch : line1 ) {
			items1.insert(ch);
		}
		for (auto &ch : line2 ) {
			items2.insert(ch);
		}
		for (auto &ch : line3 ) {
			items3.insert(ch);
		}
		for (auto &ch : items1 ) {
			if ( items2.find(ch) != items2.end() && items3.find(ch) != items3.end() ) {
				//std::cout << line1 << '|' << line2 << '|' << line3 << " = " << ch << std::endl;
				total2 += get_score(ch);
				break;
			}
		}
	}
	return total2;
}

int main() {
	//do_first();
	uint32_t t2 = do_second();
	std::cout << t2 << std::endl;
	return 0;
}
