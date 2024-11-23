#include <iostream>
#include <string>
#include <mutex>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>

class UserActivityLogger {
private:
    mutable std::mutex mtx;
    mutable std::ofstream filestream;

public:
    UserActivityLogger(const std::string& filename) {
        filestream.open(filename, std::ios::app);
        if(!filestream.is_open()) {
            throw std::runtime_error("Failed to open log file.");
        }
    }

    ~UserActivityLogger() {
        if(filestream.is_open()) {
            filestream.close();
        }
    }

    void logActivity(const std::string& user, const std::string& activity) const {
        std::lock_guard<std::mutex> lock(mtx);
        if(filestream.is_open()) {
            filestream << "[User: " << user << "] Activity: " << activity << "[Timestamp: " << getCurrentTimestamp() << "]\n"; 
        }
        else {
            throw std::runtime_error("Log file is not open.");
        }
    }

private:
    std::string getCurrentTimestamp() const {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto in_time_t = system_clock::to_time_t(now);

        char buffer[30];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&in_time_t));

        return std::string(buffer);
    }
};

void simulateUserActivity(const UserActivityLogger& logger, const std::string& user, int activityCount) {
    for(int i = 0; i < activityCount; ++i) {
        logger.logActivity(user, "Performed an action");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    UserActivityLogger logger("user_activity_logger.txt");

    std::vector<std::thread> threads;
    threads.emplace_back(simulateUserActivity, std::cref(logger), "Alice", 5);
    threads.emplace_back(simulateUserActivity, std::cref(logger), "Bob", 7);
    threads.emplace_back(simulateUserActivity, std::cref(logger), "Charlie", 9);

    for(auto& t : threads) {
        t.join();
    }

    std::cout << "All used activities have been logged successfully.\n";

    return 0;
}