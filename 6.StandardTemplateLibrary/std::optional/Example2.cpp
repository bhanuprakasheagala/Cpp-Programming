#include <iostream>
#include <optional>

std::optional<int> findNumber(int number, const std::vector<int>& data) {
    for(int val : data) {
        if(val == number) {
            return val;
        }
    }
    return std::nullopt; // return disengaged optional
}

int main()
{
    std::vector<int> data = {1, 3, 5, 7, 2, 4, 6, 8};
    auto res = findNumber(3, data);
    if(res) {
        std::cout << "Found: " << *res << '\n';
    }
    else {
        std::cout << "Number not found\n";
    }

    auto res2 = findNumber(9, data);
    if(res2) {
        std::cout << "Found: " << *res2 << '\n';
    }
    else {
        std::cout << "Number not found\n";
    }

    return 0;
}