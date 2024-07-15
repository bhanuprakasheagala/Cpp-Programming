#include <iostream>
#include <unordered_map>
#include <string>

class KeyValueStore {
    public:
        // Adds or updates a key-value pair
        void put(const std::string& key, const std::string& value) {
            store_[key] = value;
        }

        // Retrieves the value associated with a key
        std::string get(const std::string& key) const{
            auto it = store_.find(key);
            if(it != store_.end()) {
                return it->second;
            }
            else {
                return "Key not found!\n";
            }
        }

        // Remove key-value pair
        void remove(const std::string& key) {
            store_.erase(key);
        }

        // Checks if a key exists
        bool contains(const std::string& key) const {
            return store_.find(key) != store_.end();
        }

        private:
            std::unordered_map<std::string, std::string> store_;
};

int main()
{
    KeyValueStore kvStore;

    kvStore.put("Name", "Alice");
    kvStore.put("Age", "30");

    std::cout << "Name: " << kvStore.get("Name") << '\n';
    std::cout << "Age: " << kvStore.get("Age") << '\n';

    kvStore.remove("Age");

    std::cout << "Contains 'Age' " << kvStore.contains("Age") << '\n';
    std::cout << "Contains 'Name' " << kvStore.contains("Name") << '\n';

    return 0;
}