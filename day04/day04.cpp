#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream infile("input04.txt");
	std::string line;
	uint32_t total1 = 0;
    uint32_t total2 = 0;
	while( !infile.eof()) {
        int l1, l2, r1, r2;
        char c;
        infile >> l1 >> c >> l2 >> c >> r1 >> c >> r2;
        if ((l1 <= r1 && l2 >= r2) ||
            (r1 <= l1 && r2 >= l2) )
        {
            total1 += 1;
        }

        if (!((l1 < r1 && l2 < r1) || // left is entirely before
             (l1 > r2 )))             // left is entirely after 
        {
            total2++;
        }
    }
    std::cout << "total 1 is " << total1 << std::endl;
    std::cout << "total 2 is " << total2 << std::endl;
    return 0;
}

