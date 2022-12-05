#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>

std::vector<std::stack<char>> get_test_data() {
    std::vector<std::stack<char>> v;
    std::stack<char> s1;
    s1.push('Z');
    s1.push('N');
    v.push_back(s1);
    std::stack<char> s2;
    s2.push('M');
    s2.push('C');
    s2.push('D');
    v.push_back(s2);
    std::stack<char> s3;
    s3.push('P');
    v.push_back(s3);
    return v;
}

std::vector<std::stack<char>> get_real_data() {
    /*             [C]         [N] [R]    
       [J] [T]     [H]         [P] [L]    
       [F] [S] [T] [B]         [M] [D]    
       [C] [L] [J] [Z] [S]     [L] [B]    
       [N] [Q] [G] [J] [J]     [F] [F] [R]
       [D] [V] [B] [L] [B] [Q] [D] [M] [T]
       [B] [Z] [Z] [T] [V] [S] [V] [S] [D]
       [W] [P] [P] [D] [G] [P] [B] [P] [V]
        1   2   3   4   5   6   7   8   9  */
    std::vector<std::stack<char>> v;
    std::stack<char> s1;
    s1.push('W');
    s1.push('B');
    s1.push('D');
    s1.push('N');
    s1.push('C');
    s1.push('F');
    s1.push('J');
    v.push_back(s1);

    std::stack<char> s2;
    s2.push('P');
    s2.push('Z');
    s2.push('V');
    s2.push('Q');
    s2.push('L');
    s2.push('S');
    s2.push('T');
    v.push_back(s2);

    std::stack<char> s3;
    s3.push('P');
    s3.push('Z');
    s3.push('B');
    s3.push('G');
    s3.push('J');
    s3.push('T');
    v.push_back(s3);

    std::stack<char> s4;
    s4.push('D');
    s4.push('T');
    s4.push('L');
    s4.push('J');
    s4.push('Z');
    s4.push('B');
    s4.push('H');
    s4.push('C');
    v.push_back(s4);

    std::stack<char> s5;
    s5.push('G');
    s5.push('V');
    s5.push('B');
    s5.push('J');
    s5.push('S');
    v.push_back(s5);

    std::stack<char> s6;
    s6.push('P');
    s6.push('S');
    s6.push('Q');
    v.push_back(s6);

    std::stack<char> s7;
    s7.push('B');
    s7.push('V');
    s7.push('D');
    s7.push('F');
    s7.push('L');
    s7.push('M');
    s7.push('P');
    s7.push('N');
    v.push_back(s7);

    std::stack<char> s8;
    s8.push('P');
    s8.push('S');
    s8.push('M');
    s8.push('F');
    s8.push('B');
    s8.push('D');
    s8.push('L');
    s8.push('R');
    v.push_back(s8);

    std::stack<char> s9;
    s9.push('V');
    s9.push('D');
    s9.push('T');
    s9.push('R');
    v.push_back(s9);

    return v;
}

int main() {
    std::ifstream infile("input05.txt");
    std::string line;
    std::vector<std::stack<char>> s1 = get_real_data();
    std::string s;

    while (std::getline(infile, s))
    {   // scan until we find the blank line
        if (s == "") {
            break;
        }
    }

    while (!infile.eof()) {
        // move 1 from 2 to 1
        int num, from, to;
        infile >> s >> num >> s >> from >> s >> to;

        for (int i = 0; i < num; i++) {
            char c = s1[from-1].top();
            s1[from - 1].pop();
            s1[to - 1].push(c);
        }
    }
    for (auto s : s1) {
        std::cout << s.top();
    }
    std::cout << std::endl;
    //std::cout << "total 1 is " << total1 << std::endl;
    //std::cout << "total 2 is " << total2 << std::endl;
    return 0;
}

