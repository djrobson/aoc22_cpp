#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>

using namespace std;

int main()
{
    ifstream file;

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';

    file.open("input02.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file." << endl;
        return 0;
    }

    // rock = 1, paper = 2, scissor = 3, loss = 0, tie = 3, win = 6
    map<string, uint32_t> first;
    first.insert(pair("A X", 1+3));
    first.insert(pair("A Y", 2+6));
    first.insert(pair("A Z", 3+0));

    first.insert(pair("B X", 1+0));
    first.insert(pair("B Y", 2+3));
    first.insert(pair("B Z", 3+6));

    first.insert(pair("C X", 1+6));
    first.insert(pair("C Y", 2+0));
    first.insert(pair("C Z", 3+3));

    // rock = 1, paper = 2, scissor = 3, loss = 0, tie = 3, win = 6
    map<string, uint32_t> second;
    second.insert(pair("A X", 3 + 0)); // rock scissor lose
    second.insert(pair("A Y", 1 + 3)); // rock rock draw
    second.insert(pair("A Z", 2 + 6)); // rock paper win

    second.insert(pair("B X", 1 + 0)); // paper rock lose
    second.insert(pair("B Y", 2 + 3)); // paper paper draw
    second.insert(pair("B Z", 3 + 6)); // paper scissor win

    second.insert(pair("C X", 2 + 0)); // scissor paper lose
    second.insert(pair("C Y", 3 + 3)); // scissor scissor draw
    second.insert(pair("C Z", 1 + 6)); // scissor rock win

    uint32_t first_total = 0;
    uint32_t second_total = 0;

    string line;
    while (getline(file, line))
    {
        first_total += first[line];
        second_total += second[line];
    }

    file.close();
    cout << "first score is: " << first_total << endl << "second score is: "<< second_total << endl;
    return 0;
}

