#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
struct top_three {
    int one;
    int two;
    int three;
};

void insert_new(struct top_three& max, int next) {
    if (next > max.one) {
        max.three = max.two;
        max.two = max.one;
        max.one = next;
    } else if (next > max.two) {
        max.three = max.two;
        max.two = next;
    }
    else if (next > max.three) {
        max.three = next;
    }
}

int main()
{
    ifstream file;

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';

    file.open("input01.txt");
    if (!file.is_open())
    {
        cout << "Unable to open the file." << endl;
        return 0;
    }
    struct top_three max;
    int this_total = 0;

    string line;
    while (getline(file, line))
    {
        if (line == "")
        {
            insert_new(max, this_total);
            this_total = 0;
        } else {
            int num = stoi(line);
            this_total += num;
        }
    }

    file.close();
    cout << "max cal is: " << (max.one + max.two + max.three) << endl;
    return 0;
}

