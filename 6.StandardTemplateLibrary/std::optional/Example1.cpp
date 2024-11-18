#include <iostream>
#include <optional>

int main()
{
    std::optional<int> opt1; // Disengaged
    std::optional<int> opt2 = 42; // Engaged with value 42
    std::optional<int> opt3 = std::nullopt; // Explicitly disengaged

    std::cout << "opt1: " << (opt1.has_value() ? "Has value" : "No value") << '\n';
    std::cout << "opt2: " << (opt2.has_value() ? "Has value" : "No value") << '\n';
    std::cout << "opt3: " << (opt3.has_value() ? "Has value" : "No value") << '\n';

    return 0;
}