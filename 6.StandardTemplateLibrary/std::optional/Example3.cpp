#include <iostream>
#include <optional>
#include <string>

struct Config {
    std::optional<std::string> username;
    std::optional<int> timeout;
};

void printConfig(const Config& config) {
    std::cout << "Username: " << config.username.value_or("Guest" ) << '\n';
    std::cout << "Timeout: " << config.timeout.value_or(30) << " seconds\n";
}

int main()
{
    Config config;
    
    config.username = "Alice";

    std::cout << "Initial Config:\n";
    printConfig(config);

    config.timeout = 60;
    std::cout << "Updated Config:\n";
    printConfig(config);


    return 0;
}