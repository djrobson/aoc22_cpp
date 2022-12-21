#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <list>

struct ListItem {
    ListItem* next;
    ListItem* prev;
    int value;
};

void shift_item(ListItem* item) {
    auto cursor = item;

    int val = item->value;
    if (val == 0) {
        return;
    }

    // cut this value out of the list
    // 1<->i<->3 ==> 1<->3
    cursor->prev->next = item->next;
    cursor->next->prev = item->prev;

    if (val < 0) {
        for (int count = 0; count <= -val; count++) {
            cursor = cursor->prev;
        }
    }
    else {
        for (int count = 0; count < val; count++) {
            cursor = cursor->next;
        }
    }

    // insert after cursor
    // 1<->2<->3 ==> 1<->2<->i<->3
    item->next = cursor->next;
    item->prev = cursor;
    cursor->next->prev = item;
    cursor->next = item;

}

void PrintList(ListItem* head) {
    ListItem* start = head;
    ListItem* cursor = head;

    if (head == nullptr) {
        std::cout << "empty list\n";
        return;
    }
    do {
        std::cout << cursor->value << ", ";
        cursor = cursor->next;
    } while (cursor != start);
    std::cout << std::endl;
}

int main()
{
    std::ifstream file;

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';

    file.open("input20.txt");
    //file.open("sample.txt");
    if (!file.is_open())
    {
        std::cout << "Unable to open the file." << std::endl;
        return 0;
    }

    std::vector<ListItem*> input_addrs;
    ListItem* head = nullptr;
    ListItem* tail = nullptr;

    std::string line;
    size_t index_of_0 = 0;
    while (std::getline(file, line))
    {
        int32_t num = std::stoi(line);
        if (head == nullptr) {
            ListItem* new_item = new ListItem;
            new_item->next = new_item;
            new_item->prev = new_item;
            new_item->value = num;
            head = new_item;
            tail = head;
            input_addrs.push_back(new_item);
        } else {
            ListItem* new_item = new ListItem;
            new_item->next = tail->next;
            new_item->prev = tail;
            new_item->value = num;
            tail->next->prev = new_item;
            tail->next = new_item;
            tail = new_item;
            input_addrs.push_back(new_item);
            if (num == 0) {
                index_of_0 = input_addrs.size() - 1;
            }
        }
    }
    file.close();

    //PrintList(head);
    size_t total_nums = input_addrs.size();
    for (auto item : input_addrs) {
        //std::cout << "moving: " << item->value << std::endl;
        shift_item(item);
        //PrintList(head);
    }

    auto cursor = input_addrs[index_of_0];
    auto total = 0;
    for (int count = 0; count <= 3000; count++) {
        if (count % 1000 == 0) {
            //std::cout << cursor->value << " ";
            total += cursor->value;
        }
        cursor = cursor->next;
    }
    //std::cout << "\n";

    std::cout << "total: " << total << std::endl;
}

